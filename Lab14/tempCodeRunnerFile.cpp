// Lab 2 - Computing descriptive statistics
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

int main() {
    std::vector<double> numbers;
    double input;
    std::cout << "Enter a sequence of numbers (enter 'q' to quit): ";
    while (std::cin >> input) {
        numbers.push_back(input);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (numbers.empty()) {
        std::cout << "No numbers entered." << std::endl;
        return 0;
    }

    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    double mean = sum / numbers.size();

    std::sort(numbers.begin(), numbers.end());
    double median;
    if (numbers.size() % 2 == 0) {
        median = (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2;
    } else {
        median = numbers[numbers.size() / 2];
    }

    double squared_diff_sum = 0.0;
    for (double num : numbers) {
        squared_diff_sum += (num - mean) * (num - mean);
    }
    double std_dev = std::sqrt(squared_diff_sum / numbers.size());

    double min_num = *std::min_element(numbers.begin(), numbers.end());
    double max_num = *std::max_element(numbers.begin(), numbers.end());

    std::cout << "Mean: " << std::setprecision(2) << std::fixed << mean << std::endl;
    std::cout << "Median: " << std::setprecision(2) << std::fixed << median << std::endl;
    std::cout << "Standard Deviation: " << std::setprecision(2) << std::fixed << std_dev << std::endl;
    std::cout << "Minimum: " << std::setprecision(2) << std::fixed << min_num << std::endl;
    std::cout << "Maximum: " << std::setprecision(2) << std::fixed << max_num << std::endl;

    return 0;
}
