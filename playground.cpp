#include <iostream>

class PhoneNumber {
private:
    int areaCode;
    int exchange;
    int lineNumber;

public:
    PhoneNumber() : areaCode(0), exchange(0), lineNumber(0) {}

    friend std::istream& operator>>(std::istream& input, PhoneNumber& number);
};

std::istream& operator>>(std::istream& input, PhoneNumber& number) {
    char discard;
    input >> discard >> number.areaCode >> discard >> number.exchange >> discard >> number.lineNumber >> discard;
    
    return input;
}

int main() {
    PhoneNumber myNumber;

    // Using the overloaded operator for stream extraction
    std::cout << "Enter your Phone Number (format: (123) 456-7890): ";
    std::cin >> myNumber;

    std::cout << "You entered: " << myNumber << std::endl;

    return 0;
}
