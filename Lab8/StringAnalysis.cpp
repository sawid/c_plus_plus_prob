 #include <iostream>
#include <cstring>
#include <cctype> // for isdigit
using namespace std;

// Function to calculate the length and count of vowels
pair<unsigned int, unsigned int> mystery3(const char*);

// Function to reverse a string in place
void reverseString(char*);

int main() {
    try {
        char string1[80];

        cout << "Enter a string: ";
        cin.getline(string1, 80); // Read the entire line

        // Task 1: Calculate length and count of vowels
        auto result = mystery3(string1);
        cout << "Length of the string: " << result.first << endl;
        cout << "Number of vowels in the string: " << result.second << endl;

        // Task 2: Reverse the string
        char copiedString[80];
        strcpy(copiedString, string1); // Copy the original string
        cout << "Original: " << string1 << endl;
        reverseString(copiedString);
        cout << "Reversed: " << copiedString << endl;

        // Task 3: Convert string to integer, stopping at non-numeric characters
        char numericString[80];
        cout << "Enter a numeric string: ";
        cin.getline(numericString, 80);
        int convertedInt = atoi(numericString);
        cout << "Converted to Int: " << convertedInt << endl;

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

// Task 1: Calculate length and count of vowels
pair<unsigned int, unsigned int> mystery3(const char* s) {
    unsigned int length = 0;
    unsigned int vowelCount = 0;

    while (*s != '\0') {
        ++length;

        // Check for vowels
        char lowercaseChar = tolower(*s);
        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' || lowercaseChar == 'u') {
            ++vowelCount;
        }

        ++s;
    }

    return {length, vowelCount};
}

// Task 2: Reverse a string in place
void reverseString(char* s) {
    int length = strlen(s);
    for (int i = 0; i < length / 2; ++i) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}
