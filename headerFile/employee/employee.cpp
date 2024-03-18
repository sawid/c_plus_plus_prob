// employee.cpp

#include "employee.h"
#include <iostream>

// Constructor
Employee::Employee(int id, const std::string& name, double salary)
    : employeeID(id), employeeName(name), employeeSalary(salary) {}

// Getter functions
int Employee::getEmployeeID() const {
    return employeeID;
}

std::string Employee::getEmployeeName() const {
    return employeeName;
}

double Employee::getEmployeeSalary() const {
    return employeeSalary;
}

// Setter functions
void Employee::setEmployeeID(int id) {
    employeeID = id;
}

void Employee::setEmployeeName(const std::string& name) {
    employeeName = name;
}

void Employee::setEmployeeSalary(double salary) {
    employeeSalary = salary;
}

// Function to display employee details
void Employee::displayDetails() const {
    std::cout << "Employee ID: " << employeeID << std::endl;
    std::cout << "Employee Name: " << employeeName << std::endl;
    std::cout << "Employee Salary: " << employeeSalary << std::endl;
}
