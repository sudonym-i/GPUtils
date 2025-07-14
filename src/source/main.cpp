#include <string>
#include "lib.hpp"
#include <iostream>

// Declare the CUDA function
void addWithCuda(int* c, const int* a, const int* b, int size);

int main() {
    const int size = 5;
    int a[size] = {1, 2, 3, 4, 5};
    int b[size] = {10, 20, 30, 40, 50};
    int c[size] = {0};

    addWithCuda(c, a, b, size);

    std::cout << "Result: ";
    for (int i = 0; i < size; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

