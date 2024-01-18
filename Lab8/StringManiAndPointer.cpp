#include <iostream>
#include <cstring>
using namespace std;

void mystery1(char *s1, const char *s2) {
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);

    if (len_s1 + len_s2 < 80) {
        strcpy(s1 + len_s1, s2);
    } else {
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
    cout << "case 1 Normal concat: Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);
    cout << "Concatenated String: " << string1 << endl;

    // Case 2: Overflow
    cout << "case 2 overflow: Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);

    // Case 3: Substring
    cout << "case 3 substring: Enter two strings: ";
    cin >> string1 >> string2;
    cout << "Is string2 a substring of string1? " << (mystery2(string1, string2) ? "Yes" : "No") << endl;

    // Case 4: Non-substring
    cout << "case 4 non-substring: Enter two strings: ";
    cin >> string1 >> string2;
    cout << "Is string2 a substring of string1? " << (mystery2(string1, string2) ? "Yes" : "No") << endl;

    return 0;
}
