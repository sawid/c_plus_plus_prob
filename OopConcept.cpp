#include <iostream>
#include <string>

// Base class
class Person {
protected:
    std::string name;

public:
    Person(const std::string &name) : name(name) {}

    virtual void introduce() const {
        std::cout << "Hello, I am " << name << ". ";
    }

    virtual ~Person() {
        std::cout << "Person destructor called for " << name << std::endl;
    }
};

// Derived class inheriting from Person
class Student : public Person {
private:
    int studentID;

public:
    Student(const std::string &name, int studentID) : Person(name), studentID(studentID) {}

    void introduce() const override {
        Person::introduce();
        std::cout << "I am a student with ID " << studentID << "." << std::endl;
    }

    ~Student() override {
        std::cout << "Student destructor called for " << name << std::endl;
    }
};

// Derived class inheriting from Person
class Teacher : public Person {
private:
    std::string subject;

public:
    Teacher(const std::string &name, const std::string &subject) : Person(name), subject(subject) {}

    void introduce() const override {
        Person::introduce();
        std::cout << "I am a teacher, and I teach " << subject << "." << std::endl;
    }

    ~Teacher() override {
        std::cout << "Teacher destructor called for " << name << std::endl;
    }
};

int main() {
    // Create objects of different types
    Person person("John");
    Student student("Alice", 12345);
    Teacher teacher("Mr. Smith", "Computer Science");

    // Demonstrate polymorphism
    Person *polymorphicPointer;
    polymorphicPointer = &person;
    polymorphicPointer->introduce();

    polymorphicPointer = &student;
    polymorphicPointer->introduce();

    polymorphicPointer = &teacher;
    polymorphicPointer->introduce();

    return 0;
}
