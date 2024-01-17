#include <iostream>
using namespace std;

int multiply(int, int);

int main() {
    int x = 0;
    int y = 0;
    
    cout << "Enter two integers: ";
    cin >> x >> y;
    
    cout << "The result is " << multiply(x, y) << endl;
    
    return 0;
}

int multiply(int a, int b) {
    if (b == 0) {
        return 0; // Base case: anything multiplied by 0 is 0
    } else {
        return a + multiply(a, b - 1); // Recursive step: multiply(a, b) = a + multiply(a, b-1)
    }
}
