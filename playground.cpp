#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sum(const int &input)
{
    return input + 1;
}

int main(int argc, char const *argv[])
{
    int a = 1;
    // cout << time(nullptr);
    std::srand(std::time(nullptr));
    int numberToGuess = (std::rand() % 101) + 1; // Random number between 0 and 100

    cout << numberToGuess;
    return 0;
}
