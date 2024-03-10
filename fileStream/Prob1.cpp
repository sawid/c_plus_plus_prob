#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    int sum = 0;
    int number;

    while (inputFile >> number) {
        sum += number;
    }

    inputFile.close();

    std::cout << "Sum of integers in the file: " << sum << std::endl;

    return 0;
}