#include <iostream>

class Adder {
public:
    virtual int add(int a, int b) const {
        return a + b;
    }
};

class CustomAdder : public Adder {
public:
    int add(int a, int b) const override {
        // You can customize the addition logic here if needed
        return Adder::add(a, b);
    }
};

int main() {
    // Start with a sum variable set to zero.
    int sum = 0;

    // Take two numbers as input (10 and 20).
    int number1, number2;
    std::cout << "Enter the first number: ";
    std::cin >> number1;

    std::cout << "Enter the second number: ";
    std::cin >> number2;

    // Create an instance of Adder (polymorphic behavior).
    Adder* adder = new CustomAdder();

    // Add both numbers and save the result in the variable sum.
    sum = adder->add(number1, number2);

    // Output the value of the sum variable.
    std::cout << "The sum of " << number1 << " and " << number2 << " is: " << sum << std::endl;

    // Clean up allocated memory.
    delete adder;

    return 0;
}
