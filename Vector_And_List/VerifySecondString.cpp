// Write a C++ program to verify that all of the letters in the second string appear in the first string as well. Return true otherwise false.
#include <iostream>
#include <algorithm>

using namespace std;

bool checkLetterInString(const string& firstString, const string& secondString)
{

    string firstStringLowerCase = firstString;
    string secondStringLowerCase = secondString;
    transform(firstStringLowerCase.begin(), firstStringLowerCase.end(), firstStringLowerCase.begin(), [](char c) { return tolower(c); });
    transform(secondStringLowerCase.begin(), secondStringLowerCase.end(), secondStringLowerCase.begin(), [](char c) { return tolower(c); });

    for (char element: secondStringLowerCase)
    {
        if (std::find(firstStringLowerCase.begin(), firstStringLowerCase.end(), element) == firstStringLowerCase.end()) {
            return false;  
        }
    }

    return true;
    
}

int main()
{
    if (checkLetterInString("data", "da"))
    {
        cout << "True";
    }
    
    // cout << ;
    return 0;
}
