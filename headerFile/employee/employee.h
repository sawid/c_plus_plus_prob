// employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    int employeeID;
    std::string employeeName;
    double employeeSalary;

public:
    // Constructor
    Employee(int id, const std::string& name, double salary);

    // Getter functions
    int getEmployeeID() const;
    std::string getEmployeeName() const;
    double getEmployeeSalary() const;

    // Setter functions
    void setEmployeeID(int id);
    void setEmployeeName(const std::string& name);
    void setEmployeeSalary(double salary);

    // Function to display employee details
    void displayDetails() const;
};

#endif // EMPLOYEE_H
