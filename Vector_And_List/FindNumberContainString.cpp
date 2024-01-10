// Write a C++ program that takes a vector of strings and returns only those strings that contain a number(s). Return an empty vector if none.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> removeContainNumber(vector<string> inputVector) {
    inputVector.erase(
        remove_if(inputVector.begin(), inputVector.end(),
                  [](const string& s) {
                      return any_of(s.begin(), s.end(), ::isdigit);
                  }),
        inputVector.end()
    );

    return inputVector;
}

int main()
{
    vector<string> originalVector = {"apple", "123banana", "orange", "grape", "kiwi", "melon456"};

    cout << "Original vector: ";
    for (const string& element : originalVector) {
        cout << element << " ";
    }
    cout << endl;

    vector<string> modifiedVector = removeContainNumber(originalVector);

    cout << "Modified vector (removed elements containing numbers): ";
    for (const string& element : modifiedVector) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
