#include <iostream>

void reverseArray(int* arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        // Swap the elements at start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers towards each other
        ++start;
        --end;
    }
}

int main() {
    const int size = 5;
    int numbers[size] = {1, 2, 3, 4, 5};

    std::cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(numbers, size);

    std::cout << "Reversed Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
