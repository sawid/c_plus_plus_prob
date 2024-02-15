#include <iostream>
#include <fstream>

int main() {
    // Writing to a file
    std::ofstream outputFile("example_seek.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing\n";
        return 1;
    }

    // Writing data to the file
    outputFile << "Hello, Seek and Tell in C++!\n";
    outputFile << "This is a second line.\n";

    // Seek to a specific position in the file
    outputFile.seekp(10, std::ios_base::beg);  // Set the put pointer to the 10th position from the beginning

    // Writing additional data at the new position
    outputFile << "Inserted at position 10.\n";

    // Close the file after writing
    outputFile.close();

    // Reading from the file
    std::ifstream inputFile("example_seek.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading\n";
        return 1;
    }

    std::string line;

    // Reading lines from the file
    while (std::getline(inputFile, line)) {
        std::cout << "Read from file: " << line << '\n';
    }

    // Use tellg to get the current position of the get pointer
    std::streampos getPosition = inputFile.tellg();
    std::cout << "Current position of the get pointer: " << getPosition << '\n';

    // Seek to a specific position in the file using seekg
    inputFile.seekg(20, std::ios_base::beg);  // Set the get pointer to the 20th position from the beginning

    // Use tellg to get the new position of the get pointer
    getPosition = inputFile.tellg();
    std::cout << "New position of the get pointer: " << getPosition << '\n';

    // Reading lines from the new position
    while (std::getline(inputFile, line)) {
        std::cout << "Read from file after seeking: " << line << '\n';
    }

    // Close the file after reading
    inputFile.close();

    return 0;
}
