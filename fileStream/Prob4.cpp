#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("transactions.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string transactionType;
    double amount;
    double totalBalance = 0;

    while (inputFile >> transactionType >> amount) {
        if (transactionType == "Deposit") {
            totalBalance += amount;
        } else if (transactionType == "Withdraw") {
            totalBalance -= amount;
        } else {
            std::cerr << "Invalid transaction type: " << transactionType << std::endl;
            inputFile.close();
            return 1;
        }
    }

    inputFile.close();

    std::cout << "Total balance after processing transactions: " << totalBalance << std::endl;

    return 0;
}
