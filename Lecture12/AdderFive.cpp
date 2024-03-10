#include <iostream>

class Adder {
public:
    virtual void addNumber(int& sum, int& count) const = 0;
};

class SimpleAdder : public Adder {
public:
    void addNumber(int& sum, int& count) const override {
        int number;
        std::cout << "Enter a number: ";
        std::cin >> number;

        sum += number;
        count++;
    }
};

class CustomAdder : public Adder {
public:
    void addNumber(int& sum, int& count) const override {
        int number;
        std::cout << "Enter a custom number: ";
        std::cin >> number;

        // You can customize the addition logic here if needed
        sum += number;
        count++;
    }
};

int main() {
    // Use two variables: sum and count, both initialized to zero.
    int sum = 0;
    int count = 0;

    // Create an instance of Adder (polymorphic behavior).
    Adder* adder = new SimpleAdder();

    // Take five numbers as input, one by one.
    for (int i = 0; i < 5; ++i) {
        adder->addNumber(sum, count);
    }

    // Output the final sum.
    std::cout << "The sum of the five numbers is: " << sum << std::endl;

    // Clean up allocated memory.
    delete adder;

    return 0;
}
