#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream wordsFile("words.txt");

    if (!wordsFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    int wordCount = 0;
    int totalLength = 0;
    std::string word;

    while (wordsFile >> word) {
        wordCount++;
        totalLength += word.length();
    }

    wordsFile.close();

    if (wordCount == 0) {
        std::cout << "The file is empty." << std::endl;
    } else {
        double averageLength = static_cast<double>(totalLength) / wordCount;

        std::cout << "Number of words in the file: " << wordCount << std::endl;
        std::cout << "Average length of words: " << std::fixed << std::setprecision(2) << averageLength << " characters" << std::endl;
    }

    return 0;
}
