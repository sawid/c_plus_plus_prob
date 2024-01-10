#include <iostream>
using namespace std;

class Converttemp
{
private:
    int temp;
    char mode;
public:
    Converttemp(int temp, char mode) : temp(temp) , mode(mode)
    {

    }

    float getTemperature() const {
        if (mode == 'c' || mode == 'C')
        {
            return (temp - 32) * 5/9;
        }
        else if (mode == 'f' || mode == 'f')
        {
            return (temp * 9/5) + 32;
        }
    }
    
};

int main()
{
    bool stillRunning = true;
    int temp;
    while (stillRunning) {
        cout << "Enter temperature";
        cin >> temp;
        cout << "Enter temperature";
        char mode;
        cin >> mode;
        
    }
    return 0;
}