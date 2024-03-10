#include <iostream>

int main() {
    const int size = 5;
    int numbers[size] = {10, 5, 8, 20, 15};

    int *maxElement = nullptr;
    int maxIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (maxElement == nullptr || numbers[i] > *maxElement) {
            maxElement = &numbers[i];
            maxIndex = i;
        }
    }

    if (maxElement != nullptr) {
        std::cout << "Maximum element: " << *maxElement << std::endl;
        std::cout << "Index of the maximum element: " << maxIndex << std::endl;
    } else {
        std::cout << "The array is empty." << std::endl;
    }

    return 0;
}
