#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile("grades.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string name;
    int grade;
    std::vector<std::string> aboveAverageNames;
    int totalGrades = 0;
    int studentCount = 0;

    while (inputFile >> name >> grade) {
        totalGrades += grade;
        studentCount++;
    }

    inputFile.close();

    if (studentCount == 0) {
        std::cout << "The file is empty." << std::endl;
    } else {
        double averageGrade = static_cast<double>(totalGrades) / studentCount;

        std::cout << "Average grade for all students: " << averageGrade << std::endl;

        // Open the file again to read names of students above average
        inputFile.open("grades.txt");

        while (inputFile >> name >> grade) {
            if (grade > averageGrade) {
                aboveAverageNames.push_back(name);
            }
        }

        inputFile.close();

        if (!aboveAverageNames.empty()) {
            std::cout << "Names of students above average: ";
            for (const auto& student : aboveAverageNames) {
                std::cout << student << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No students scored above the average." << std::endl;
        }
    }

    return 0;
}
