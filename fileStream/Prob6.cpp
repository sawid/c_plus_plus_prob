#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int main() {
    std::ifstream inputFile("temperatures.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string date;
    double temperature;
    double totalTemperature = 0;
    double highestTemperature = std::numeric_limits<double>::min();
    std::string dateOfHighestTemp;

    int dataCount = 0;

    while (inputFile >> date >> temperature) {
        totalTemperature += temperature;
        dataCount++;

        if (temperature > highestTemperature) {
            highestTemperature = temperature;
            dateOfHighestTemp = date;
        }
    }

    inputFile.close();

    if (dataCount == 0) {
        std::cout << "No temperature data available." << std::endl;
    } else {
        double averageTemperature = totalTemperature / dataCount;

        std::cout << "Average temperature: " << averageTemperature << " Celsius" << std::endl;
        std::cout << "Highest temperature: " << highestTemperature << " Celsius" << std::endl;
        std::cout << "Date of highest temperature: " << dateOfHighestTemp << std::endl;
    }

    return 0;
}
