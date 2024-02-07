#include <iostream>
#include <sstream>

class Fraction
{
private:
    int numerator;
    int denominator;

    // Helper function to find the greatest common divisor (GCD)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper function to simplify the fraction
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        // Ensure the negative sign is on the numerator
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructors
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) : numerator(num), denominator(den)
    {
        simplify();
    }

    // Overloaded operators for arithmetic operations
    Fraction operator+(const Fraction &other) const
    {
        return Fraction((numerator * other.denominator) + (other.numerator * denominator), denominator * other.denominator);
    }

    Fraction operator-(const Fraction &f) const
    {
        Fraction result;
        result.numerator = (numerator * f.denominator) - (f.numerator * denominator);
        result.denominator = denominator * f.denominator;
        result.simplify();
        return result;
    }

    Fraction operator*(const Fraction &other) const
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction &other) const
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Overloaded comparison operators
    bool operator==(const Fraction &other) const
    {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    bool operator>(const Fraction &other) const
    {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    bool operator<(const Fraction &other) const
    {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    // Overloaded input operator
    friend std::istream &operator>>(std::istream &input, Fraction &fraction)
    {
        char slash;
        input >> fraction.numerator >> slash >> fraction.denominator;
        fraction.simplify();
        return input;
    }

    // Overloaded output operator
    friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction)
    {
        output << fraction.numerator;
        if (fraction.denominator != 1)
        {
            output << '/' << fraction.denominator;
        }
        return output;
    }
};

int main()
{
    Fraction f1, f2;
    std::cout << "Enter first fraction (format a/b): ";
    std::cin >> f1;
    std::cout << "Enter second fraction (format a/b): ";
    std::cin >> f2;

    std::cout << "f1 + f2 = " << (f1 + f2) << std::endl;
    std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;
    std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;
    std::cout << "f1 / f2 = " << (f1 / f2) << std::endl;

    if (f1 == f2)
        std::cout << "f1 is equal to f2" << std::endl;
    if (f1 > f2)
        std::cout << "f1 is greater than f2" << std::endl;
    if (f1 < f2)
        std::cout << "f1 is less than f2" << std::endl;

    return 0;
}