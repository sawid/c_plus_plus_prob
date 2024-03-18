// main.cpp

#include <iostream>
#include <string>
#include "student.h"

int main() {
    Student student1;
    inputStudentData(student1);
    displayStudentData(student1);

    return 0;
}

// g++ main.cpp student.cpp -o main