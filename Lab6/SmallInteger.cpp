#include <iostream>

int main() {
    // Prompt user to enter the number of integers
    int numIntegers;

    std::cout << "Enter the number of integers: ";
    std::cin >> numIntegers;

    // Check if the input is a positive integer
    if (numIntegers <= 0) {
        std::cout << "Please enter a positive integer greater than 0." << std::endl;
        return 1;  // Terminate the program with an error code
    }

    // Prompt user to enter the integers
    int smallestInteger;

    std::cout << "Enter " << numIntegers << " integers:" << std::endl;

    for (int i = 0; i < numIntegers; ++i) {
        int currentInteger;
        std::cout << "Integer " << i + 1 << ": ";
        std::cin >> currentInteger;

        // Initialize smallestInteger with the first input
        if (i == 0 || currentInteger < smallestInteger) {
            smallestInteger = currentInteger;
        }
    }

    // Display the smallest integer
    std::cout << "The smallest integer is: " << smallestInteger << std::endl;

    return 0;  // Terminate the program successfully
}
