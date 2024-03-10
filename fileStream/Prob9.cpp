#include <iostream>

int main() {
    int size;

    // Get the size of the array from the user
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Dynamically allocate memory for the array
    int *arr = new int[size];

    // Get values for each element from the user
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Calculate the sum of the array elements
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    // Display the sum
    std::cout << "Sum of array elements: " << sum << std::endl;

    // Deallocate the dynamically allocated memory
    delete[] arr;

    return 0;
}
