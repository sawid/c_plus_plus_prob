#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getter functions
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Overloading + operator for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloading - operator for subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Overloading * operator for multiplication
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    // Overloading / operator for division
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator,
                       (imaginary * other.real - real * other.imaginary) / denominator);
    }

    // Overloading == operator for equality comparison
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    // Function to display complex number
    void display() const {
        std::cout << real << " + " << imaginary << "i";
    }
};

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(4.0, -1.0);

    std::cout << "c1 = ";
    c1.display();
    std::cout << std::endl;

    std::cout << "c2 = ";
    c2.display();
    std::cout << std::endl;

    Complex result;

    // Addition
    result = c1 + c2;
    std::cout << "Addition: ";
    result.display();
    std::cout << std::endl;

    // Subtraction
    result = c1 - c2;
    std::cout << "Subtraction: ";
    result.display();
    std::cout << std::endl;

    // Multiplication
    result = c1 * c2;
    std::cout << "Multiplication: ";
    result.display();
    std::cout << std::endl;

    // Division
    result = c1 / c2;
    std::cout << "Division: ";
    result.display();
    std::cout << std::endl;

    // Equality comparison
    if (c1 == c2) {
        std::cout << "c1 and c2 are equal" << std::endl;
    } else {
        std::cout << "c1 and c2 are not equal" << std::endl;
    }

    return 0;
}
