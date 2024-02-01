#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Constructor
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Member function to display information about the person
    void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating an object of the Person class
    Person person1("John Doe", 25);

    // Using the dot operator to access members of the object
    std::cout << "Using Dot Operator:\n";
    std::cout << "Name: " << person1.name << ", Age: " << person1.age << std::endl;

    // Creating a pointer to a Person object
    Person* personPtr = &person1;

    // Using the arrow operator to access members through a pointer
    std::cout << "\nUsing Arrow Operator:\n";
    std::cout << "Name: " << personPtr->name << ", Age: " << personPtr->age << std::endl;

    // Calling a member function using the dot operator
    std::cout << "\nUsing Dot Operator to Call Member Function:\n";
    person1.displayInfo();

    // Calling a member function using the arrow operator through a pointer
    std::cout << "\nUsing Arrow Operator to Call Member Function:\n";
    personPtr->displayInfo();

    return 0;
}
