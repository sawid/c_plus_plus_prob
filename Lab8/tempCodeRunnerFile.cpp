#include <iostream>
#include <cstring>
using namespace std;

void mystery1(char *s1, const char *s2) {
    // Check if string1 has enough space to concatenate string2
    while (*s1 != '\0') ++s1;

    // Check if there is enough space in string1 for concatenation
    while (*s2 != '\0' && s1 - s2 < 80) {
        *s1 = *s2;
        ++s1;
        ++s2;
    }

    // Print an error message if there is not enough space
    if (s1 - s2 >= 80) {
        cout << "Error: Insufficient space for concatenation." << endl;
    }
}

bool mystery2(const char *s1, const char *s2) {
    return strstr(s1, s2) != nullptr;
}

int main() {
    char string1[80];
    char string2[80];

    // Case 1: Normal concat
    cout << "Case 1 Normal concat: Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);
    cout << "Concatenated String: " << string1 << endl;

    // Case 2: Overflow
    cout << "\nCase 2 overflow: Enter two strings: ";
    cin.ignore(); // Clear the input buffer
    cin.getline(string1, 80);
    cin.getline(string2, 80);
    mystery1(string1, string2);

    // Case 3: Substring
    cout << "\nCase 3 substring: Enter two strings: ";
    cin >> string1 >> string2;
    cout << "Is string2 a substring of string1? " << (mystery2(string1, string2) ? "Yes" : "No") << endl;

    // Case 4: Non-substring
    cout << "\nCase 4 non substring: Enter two strings: ";
    cin >> string1 >> string2;
    cout << "Is string2 a substring of string1? " << (mystery2(string1, string2) ? "Yes" : "No") << endl;

    return 0;
}
