#include <torch/torch.h>
#include <iostream>

// Define a multi-layer neural network class
struct MultiLayerModel : torch::nn::Module {
    torch::nn::Linear fc1, fc2, fc3;

    // Constructor
    MultiLayerModel() 
        : fc1(10, 64),  // Input layer (10 inputs to 64 neurons)
          fc2(64, 32),  // Hidden layer (64 to 32 neurons)
          fc3(32, 5)    // Output layer (32 to 5 outputs)
    {
        // Register the layers as part of the model
        register_module("fc1", fc1);
        register_module("fc2", fc2);
        register_module("fc3", fc3);
    }
     torch::Tensor operator()(torch::Tensor x) {
        return forward(x);
    }


    // Forward pass
    torch::Tensor forward(torch::Tensor x) {
        x = torch::relu(fc1(x));  // Apply ReLU activation after first layer
        x = torch::relu(fc2(x));  // Apply ReLU activation after second layer
        x = fc3(x);               // Output layer (no activation)
        return x;
    }
};

// Function to compute accuracy
float compute_accuracy(const torch::Tensor& outputs, const torch::Tensor& targets) {
    // Get the predicted class index by taking the argmax over the output tensor
    auto predicted_classes = outputs.argmax(1);  // argmax to get the predicted class indices
    auto correct = predicted_classes.eq(targets); // Compare with true labels (targets)
    float accuracy = correct.sum().item<float>() / targets.size(0);  // Compute accuracy
    return accuracy;
}


int main() {
   // Create the model instance
    MultiLayerModel model;

    // Define a loss function and optimizer
    torch::nn::CrossEntropyLoss criterion;
    torch::optim::SGD optimizer(model.parameters(), 0.01);

    // Create random data (batch size 3, 10 input features)
    torch::Tensor inputs = torch::randn({3, 10});
    torch::Tensor targets = torch::randint(0, 5, {3});  // Random targets for 5 classes

    // Training loop (example with 100 iterations)
    for (size_t epoch = 1; epoch <= 100; ++epoch) {
        model.train();  // Set the model to training mode

        optimizer.zero_grad();  // Zero the gradients from the previous step
        
        // Forward pass: Compute predicted y by passing x to the model
        torch::Tensor outputs = model.forward(inputs);
        
        // Compute the loss
        torch::Tensor loss = criterion(outputs, targets);
        
        // Backward pass: Compute gradients
        loss.backward();
        
        // Optimize the weights
        optimizer.step();
        
        // Compute accuracy
        float accuracy = compute_accuracy(outputs, targets);
        
        if (epoch % 10 == 0) {
            std::cout << "Epoch [" << epoch << "/100], Loss: " << loss.item<float>() 
                      << ", Accuracy: " << accuracy * 100 << "%" << std::endl;
        }
    }

    std::cout << "Training finished." << std::endl;

    return 0;
}
