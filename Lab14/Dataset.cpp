#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip> // Include the <iomanip> header for setprecision

int main() {
    std::vector<double> numbers;
    std::string input;
    double num;

    // Input
    std::cout << "Enter numbers separated by spaces: ";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    while (iss >> num) {
        numbers.push_back(num);
    }

    // Calculate mean
    double sum = 0;
    for (double n : numbers) {
        sum += n;
    }
    double mean = sum / numbers.size();

    // Calculate median
    std::sort(numbers.begin(), numbers.end());
    double median;
    if (numbers.size() % 2 == 0) {
        median = (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2.0;
    } else {
        median = numbers[numbers.size() / 2];
    }

    // Calculate standard deviation
    double sum_squared_diff = 0;
    for (double n : numbers) {
        sum_squared_diff += (n - mean) * (n - mean);
    }
    double std_dev = sqrt(sum_squared_diff / numbers.size());

    // Calculate minimum and maximum
    double minimum = *std::min_element(numbers.begin(), numbers.end());
    double maximum = *std::max_element(numbers.begin(), numbers.end());

    // Display results
    std::cout << "Mean: " << std::fixed << std::setprecision(2) << mean << std::endl;
    std::cout << "Median: " << std::fixed << std::setprecision(2) << median << std::endl;
    std::cout << "Standard Deviation: " << std::fixed << std::setprecision(2) << std_dev << std::endl;
    std::cout << "Minimum: " << std::fixed << std::setprecision(2) << minimum << std::endl;
    std::cout << "Maximum: " << std::fixed << std::setprecision(2) << maximum << std::endl;

    return 0;
}
