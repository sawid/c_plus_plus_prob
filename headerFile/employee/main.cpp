// main.cpp

#include <iostream>
#include "employee.h"

int main() {
    // Creating employee objects
    Employee emp1(101, "John Doe", 50000);
    Employee emp2(102, "Jane Smith", 60000);

    // Displaying initial details
    std::cout << "Employee Details:" << std::endl;
    emp1.displayDetails();
    std::cout << std::endl;
    emp2.displayDetails();
    std::cout << std::endl;

    // Modifying details
    emp1.setEmployeeSalary(55000);
    emp2.setEmployeeName("Jane Doe");

    // Displaying modified details
    std::cout << "Modified Employee Details:" << std::endl;
    emp1.displayDetails();
    std::cout << std::endl;
    emp2.displayDetails();

    return 0;
}

// g++ main.cpp employee.cpp -o employee_management
