#include <torch/torch.h>
#include <iostream>


//export DYLD_LIBRARY_PATH=/usr/local/lib:$DYLD_LIBRARY_PATH
//g++ -std=c++17 -I/usr/local/include -I/usr/local/include/torch/csrc/api/include  -L/usr/local/lib -o knn_example knn_example.cpp -ltorch -ltorch_cpu -lc10 -lpthread   -v

int main() {

    torch::Device device = torch::kCPU; // Default to CPU
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Using GPU." << std::endl;
        device = torch::Device(torch::kCUDA);
    } else {
        std::cout << "CUDA not available. Using CPU." << std::endl;
    }

    // Create two random tensors
    torch::Tensor tensor1 = torch::rand({2, 3}, device);
    torch::Tensor tensor2 = torch::rand({2, 3}, device);

    // Print the tensors
    std::cout << "Tensor 1: " << tensor1 << std::endl;
    std::cout << "Tensor 2: " << tensor2 << std::endl;

    // Perform a simple tensor addition
    torch::Tensor result = tensor1 + tensor2;

    // Print the result
    std::cout << "Result of addition: " << result << std::endl;

    return 0;
}
