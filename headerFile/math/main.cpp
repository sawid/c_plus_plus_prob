// main.cpp

#include <iostream>
#include "mathlib.h"

int main() {
    int a = 10, b = 5;
    std::cout << "Sum: " << add(a, b) << std::endl;
    std::cout << "Difference: " << subtract(a, b) << std::endl;
    std::cout << "Product: " << multiply(a, b) << std::endl;
    std::cout << "Quotient: " << divide(a, b) << std::endl;
    return 0;
}

// g++ main.cpp mathlib.cpp -o main