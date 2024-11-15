#include <torch/torch.h>
#include <iostream>
#include <vector>

// Define the CNN model
struct CNN : torch::nn::Module {
    // Define layers
    torch::nn::Conv2d conv1, conv2;
    torch::nn::Linear fc1, fc2;

    CNN()
        : conv1(torch::nn::Conv2dOptions(1, 32, 3).stride(1).padding(1)), // 1 input channel, 32 output channels, 3x3 kernel
          conv2(torch::nn::Conv2dOptions(32, 64, 3).stride(1).padding(1)), // 32 input channels, 64 output channels
          fc1(64 * 7 * 7, 128),  // Fully connected layer (flattened input size to 128)
          fc2(128, 10)           // Output layer (10 classes)
    {
        // Register the layers
        register_module("conv1", conv1);
        register_module("conv2", conv2);
        register_module("fc1", fc1);
        register_module("fc2", fc2);
    }
     torch::Tensor operator()(torch::Tensor x) {
        return forward(x);
    }
    // Forward pass
    torch::Tensor forward(torch::Tensor x) {
        // First convolutional layer + ReLU + MaxPooling
        x = torch::relu(conv1(x));
        x = torch::max_pool2d(x, 2); // 2x2 max pooling

        // Second convolutional layer + ReLU + MaxPooling
        x = torch::relu(conv2(x));
        x = torch::max_pool2d(x, 2);

        // Flatten the output for the fully connected layers
        x = x.view({x.size(0), -1}); // Reshape to (batch_size, flattened_features)

        // Fully connected layers + ReLU
        x = torch::relu(fc1(x));
        x = fc2(x); // Output layer (logits)
        return x;
    }
};

// Function to compute accuracy
float compute_accuracy(const torch::Tensor& outputs, const torch::Tensor& targets) {
    auto predicted_classes = outputs.argmax(1); // Get predicted class
    auto correct = predicted_classes.eq(targets); // Compare with ground truth
    float accuracy = correct.sum().item<float>() / targets.size(0); // Accuracy calculation
    return accuracy;
}

int main() {
    // Create the model instance
    CNN model;

    // Define a loss function and optimizer
    torch::nn::CrossEntropyLoss criterion;
    torch::optim::SGD optimizer(model.parameters(), 0.01);

    // Simulate training data (batch size 8, 1 input channel, 28x28 images)
    torch::Tensor inputs = torch::randn({8, 1, 28, 28});   // 8 grayscale images
    torch::Tensor targets = torch::randint(0, 10, {8});    // Random labels (10 classes)

    // Training loop (example with 10 epochs)
    for (size_t epoch = 1; epoch <= 10; ++epoch) {
        model.train(); // Set the model to training mode

        optimizer.zero_grad(); // Reset gradients

        // Forward pass
        torch::Tensor outputs = model.forward(inputs);

        // Compute the loss
        torch::Tensor loss = criterion(outputs, targets);

        // Backward pass
        loss.backward();

        // Update weights
        optimizer.step();

        // Compute training accuracy
        float accuracy = compute_accuracy(outputs, targets);

        std::cout << "Epoch [" << epoch << "/10], Loss: " << loss.item<float>() 
                  << ", Accuracy: " << accuracy * 100 << "%" << std::endl;
    }

    std::cout << "Training finished." << std::endl;

    return 0;
}
