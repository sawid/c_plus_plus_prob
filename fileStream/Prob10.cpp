#include <iostream>
#include <string>

int main() {
    int numStudents;

    // Get the number of students from the user
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    // Dynamically allocate memory for arrays
    std::string *names = new std::string[numStudents];
    double *scores = new double[numStudents];

    // Get names and scores from the user
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin >> names[i];

        std::cout << "Enter score for " << names[i] << ": ";
        std::cin >> scores[i];
    }

    // Calculate the average score
    double sum = 0;
    for (int i = 0; i < numStudents; ++i) {
        sum += scores[i];
    }
    double averageScore = sum / numStudents;

    // Display the average score
    std::cout << "Average score: " << averageScore << std::endl;

    // Deallocate dynamically allocated memory
    delete[] names;
    delete[] scores;

    return 0;
}
