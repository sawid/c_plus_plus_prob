// student.cpp

#include <iostream>
#include "student.h"

void inputStudentData(Student& student) {
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name);

    std::cout << "Enter roll number: ";
    std::cin >> student.rollNumber;

    std::cout << "Enter marks obtained: ";
    std::cin >> student.marks;
}

void displayStudentData(const Student& student) {
    std::cout << "Student Name: " << student.name << std::endl;
    std::cout << "Roll Number: " << student.rollNumber << std::endl;
    std::cout << "Marks Obtained: " << student.marks << std::endl;
}
