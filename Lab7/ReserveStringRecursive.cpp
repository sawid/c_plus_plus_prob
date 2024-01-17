#include <iostream>
#include <string>

using namespace std;

// Recursive function to reverse a string
void reverseString(const string& str, int index) {
    if (index >= 0) {
        cout << str[index];
        reverseString(str, index - 1);
    }
}

int main() {
    string userString;

    // Prompt user to input a string
    cout << "Enter a string: ";
    getline(cin, userString);

    // Display the reversed string using the recursive function
    cout << "Reversed String: ";
    reverseString(userString, userString.length() - 1);

    cout << endl;

    return 0;
}
