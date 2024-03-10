#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("inventory.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string itemName;
    int quantity;
    std::string maxQuantityItem;
    int maxQuantity = -1; // Initialize to a negative value to ensure any valid quantity is greater

    while (inputFile >> itemName >> quantity) {
        if (quantity > maxQuantity) {
            maxQuantity = quantity;
            maxQuantityItem = itemName;
        }
    }

    inputFile.close();

    if (maxQuantityItem.empty()) {
        std::cout << "The inventory is empty." << std::endl;
    } else {
        std::cout << "Item with the highest quantity: " << maxQuantityItem << std::endl;
        std::cout << "Quantity in stock: " << maxQuantity << std::endl;
    }

    return 0;
}
