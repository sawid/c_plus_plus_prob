#include <iostream>
#include <iomanip>

class PopulationGrowth {
private:
    double initialPopulation;
    double annualGrowthRate;

public:
    PopulationGrowth(double initial, double growthRate)
        : initialPopulation(initial), annualGrowthRate(growthRate) {}

    void calculateGrowth(int years) {
        std::cout << std::setw(5) << "Year" << std::setw(25) << "Projected Population" << std::setw(20) << "Annual Increase\n";

        double population = initialPopulation;
        double annualIncrease;

        for (int year = 1; year <= years; ++year) {
            annualIncrease = population * (annualGrowthRate / 100);
            population += annualIncrease;

            std::cout << std::setw(5) << year << std::fixed << std::setprecision(0)
                      << std::setw(25) << population << std::setprecision(0)
                      << std::setw(20) << annualIncrease << std::endl;

            if (population >= 2 * initialPopulation) {
                std::cout << "\nThe population is projected to double by year " << year << ".\n";
                break;
            }
        }
    }
};

int main() {
    double currentPopulation;
    double growthRate;

    std::cout << "Enter the current world population: ";
    std::cin >> currentPopulation;

    std::cout << "Enter the annual growth rate (percentage): ";
    std::cin >> growthRate;

    PopulationGrowth worldPopulation(currentPopulation, growthRate);

    int projectionYears = 75;
    worldPopulation.calculateGrowth(projectionYears);

    return 0;
}
