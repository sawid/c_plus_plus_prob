#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    // Vector: Dynamic array
    std::vector<int> vectorExample = {1, 2, 3, 4, 5};

    // List: Doubly-linked list
    std::list<int> listExample = {1, 2, 3, 4, 5};

    cout << vectorExample[0];

    auto it = std::next(listExample.begin(), 1);
    cout << *it << endl;
    return 0;
}
