#include <iostream>
#include <cstring>

class MyString {
private:
    char *str;

public:
    // Constructor
    MyString(const char* s = nullptr) {
        if (s != nullptr) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = new char[1];
            str[0] = '\0';
        }
    }

    // Destructor
    ~MyString() {
        delete[] str;
    }

    // Setter function to set string data
    void setString(const char* s) {
        delete[] str;
        if (s != nullptr) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = new char[1];
            str[0] = '\0';
        }
    }

    // Getter function to get string data
    const char* getString() const {
        return str;
    }

    // Function to display the string
    void display() const {
        std::cout << str;
    }

    // Overloading + operator for string concatenation
    MyString operator+(const MyString& other) const {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        MyString result(temp);
        delete[] temp;
        return result;
    }

    // Overloading + operator for concatenating a string with a character
    MyString operator+(char ch) const {
        char* temp = new char[strlen(str) + 2];
        strcpy(temp, str);
        temp[strlen(str)] = ch;
        temp[strlen(str) + 1] = '\0';
        MyString result(temp);
        delete[] temp;
        return result;
    }

    // Overloading + operator for concatenating a character with a string
    friend MyString operator+(char ch, const MyString& s) {
        char* temp = new char[strlen(s.str) + 2];
        temp[0] = ch;
        strcpy(temp + 1, s.str);
        MyString result(temp);
        delete[] temp;
        return result;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");

    // Display strings
    std::cout << "s1: ";
    s1.display();
    std::cout << std::endl;

    std::cout << "s2: ";
    s2.display();
    std::cout << std::endl;

    // Concatenation of two strings
    MyString s3 = s1 + s2;
    std::cout << "s3 = s1 + s2: ";
    s3.display();
    std::cout << std::endl;

    // Concatenation of a string with a character
    MyString s4 = s1 + '!';
    std::cout << "s4 = s1 + '!': ";
    s4.display();
    std::cout << std::endl;

    // Concatenation of a character with a string
    MyString s5 = '+' + s2;
    std::cout << "s5 = '+' + s2: ";
    s5.display();
    std::cout << std::endl;

    return 0;
}
