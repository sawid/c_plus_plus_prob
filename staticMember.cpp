#include <iostream>

class MyClass {
public:
    static int staticVariable; // Declaration
    int instanceVariable;

    MyClass(int value) : instanceVariable(value) {}

    static void staticFunction() {
        // Static function can only access static members
        std::cout << "Static Variable: " << staticVariable << std::endl;
    }
};

// Definition and initialization of staticVariable
int MyClass::staticVariable = 42;

int main() {
    MyClass obj1(10);
    MyClass obj2(20);

    // Accessing static member through the class name
    std::cout << "Static Variable: " << MyClass::staticVariable << std::endl;

    // Accessing static member through an instance (not recommended)
    std::cout << "Static Variable via Instance: " << obj1.staticVariable << std::endl;

    // Accessing instance variable
    std::cout << "Instance Variable (obj1): " << obj1.instanceVariable << std::endl;

    // Calling static member function
    MyClass::staticFunction();

    return 0;
}
