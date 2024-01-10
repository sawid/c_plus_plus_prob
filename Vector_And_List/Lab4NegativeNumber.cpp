#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

using namespace std;

vector<double> removeNegativeVector(vector<double> inputVector)
{

    inputVector.erase(
        remove_if(inputVector.begin(), inputVector.end(), [](double element) {
            return element < 0;
        }),
        inputVector.end()
    );

    return inputVector;
    
}

list<double> removeNegativeList(list<double> inputList)
{

    inputList.remove_if([](double value) {
        return value < 0;
    });
    
    return inputList;

}

int main()
{
    vector<double> vec = {0.8, -5.1, 1.6, -6.5, 10.5};

    vector<double> resultVector = removeNegativeVector(vec);

    // Display the modified vector
    for (double element : resultVector)
    {
        cout << element << " ";
    }

    cout << endl;

    list<double> lst = {0.8, -5.1, 1.6, -6.5, 10.5};

    list<double> resultList = removeNegativeList(lst);

    // Display the modified vector
    for (double element : resultList)
    {
        cout << element << " ";
    }

    return 0;
}
