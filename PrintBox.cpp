#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::cout << "Player 1: ";
    std::string p1_name = "Mike";
    // std::cin >> p1_name;
    std::cout << "Player 2: ";
    std::string p2_name = "Aut";
    // std::cin >> p2_name;
    std::cout << "**********************************\n";
    std::cout << "*                                *\n";

    std::cout << "* Player 1: " << p1_name;

    std::cout << " * Player 2: " << p2_name << " *" << std::endl;


    std::cout << "*                                *\n";
    std::cout << "**********************************\n";

    return 0;
}
