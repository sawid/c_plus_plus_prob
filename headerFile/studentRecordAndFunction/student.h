// student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    int rollNumber;
    float marks;
};

void inputStudentData(Student& student);
void displayStudentData(const Student& student);

#endif // STUDENT_H
