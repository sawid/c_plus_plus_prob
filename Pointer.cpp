#include <iostream>

int main() {
    int myNumber = 42;  // Declare and initialize an integer variable
    int* pointerToNumber = &myNumber;  // Declare a pointer and assign the address of myNumber to it

    // Access the value using the pointer
    std::cout << "Value of myNumber: " << myNumber << std::endl;
    std::cout << "Value obtained using pointer: " << *pointerToNumber << std::endl;

    return 0;
}
