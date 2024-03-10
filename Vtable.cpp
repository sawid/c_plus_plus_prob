#include <iostream>

// Base class with a virtual function
class Base {
public:
    virtual void show() const {
        std::cout << "Base class show()" << std::endl;
    }
};

// Derived class overriding the virtual function
class Derived : public Base {
public:
    void show() const override {
        std::cout << "Derived class show()" << std::endl;
    }
};

int main() {
    Base baseObject;
    Derived derivedObject;

    // Pointers to base class
    Base* basePointer1 = &baseObject;
    Base* basePointer2 = &derivedObject;

    // Calls to virtual function show()
    basePointer1->show(); // Calls Base::show()
    basePointer2->show(); // Calls Derived::show()

    return 0;
}
