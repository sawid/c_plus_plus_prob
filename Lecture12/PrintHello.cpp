#include <iostream>

class Printer {
public:
    virtual void printMessage() const = 0;
};

class HelloWorldPrinter : public Printer {
public:
    void printMessage() const override {
        std::cout << "Hello World" << std::endl;
    }
};

int main() {
    // Set a count variable to zero.
    int count = 0;

    // Create an instance of Printer (polymorphic behavior).
    Printer* printer = new HelloWorldPrinter();

    // Create a loop that will execute ten times.
    for (int i = 0; i < 10; ++i) {
        // Each time the loop executes, output the phrase "Hello World"
        // and increment the count variable.
        printer->printMessage();
        count++;
    }

    // End the loop after ten iterations.

    // Clean up allocated memory.
    delete printer;

    return 0;
}
