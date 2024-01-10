#include <iostream>
#include <vector>

using namespace std;

vector<int> leftShifting(vector<int> inputVector, int n)
{
    inputVector.erase(inputVector.begin(), inputVector.begin() + n);
    return inputVector;
}

vector<int> rightShifting(vector<int> inputVector, int n)
{
    inputVector.insert(inputVector.begin(), n, 0);
    return inputVector;
}

int main()
{
    vector<int> originalVector = {1, 2, 3, 4, 5};
    vector<int> leftShiftedVector = leftShifting(originalVector, 2);
    for (int element : leftShiftedVector)
    {
        cout << element << " ";
    }
    cout << endl;
    vector<int> rightShiftedVector = rightShifting(leftShiftedVector, 2);
    for (int element : rightShiftedVector)
    {
        cout << element << " ";
    }
    
    return 0;
}

