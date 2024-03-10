#include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr;

    Dog myDog;
    Cat myCat;

    animalPtr = &myDog;
    animalPtr->makeSound();  // Calls Dog::makeSound() at runtime

    animalPtr = &myCat;
    animalPtr->makeSound();  // Calls Cat::makeSound() at runtime

    return 0;
}
