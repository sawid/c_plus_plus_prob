// main.cpp

#include <iostream>
#include <string>
#include "student.h"

int main() {
    Student student1;
    student1.name = "Alice";
    student1.rollNumber = 101;
    student1.marks = 95.5;

    std::cout << "Student Name: " << student1.name << std::endl;
    std::cout << "Roll Number: " << student1.rollNumber << std::endl;
    std::cout << "Marks Obtained: " << student1.marks << std::endl;

    return 0;
}

// g++ main.cpp -o main