#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Recursive function to find the maximum number in an array
int findMaxRecursive(const int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }

    int maxInRest = findMaxRecursive(arr + 1, size - 1);
    return (arr[0] > maxInRest) ? arr[0] : maxInRest;
}

int main() {
    const int arraySize = 10;
    int numbers[arraySize];

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate random numbers and fill the array
    cout << "Generated Numbers: ";
    for (int i = 0; i < arraySize; ++i) {
        numbers[i] = rand() % 100 + 1;  // Random number between 1 and 100
        cout << numbers[i] << " ";
    }

    // Find the maximum number using the recursive function
    int maxNumber = findMaxRecursive(numbers, arraySize);

    // Display the maximum number
    cout << "\nMaximum Number: " << maxNumber << endl;

    return 0;
}
