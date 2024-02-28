#include <iostream>
#include <vector>

class CarbonFootprint {
public:
    virtual double calculateCarbonFootprint() const = 0;
};

class Building : public CarbonFootprint {
protected:
    double energyConsumption; // in kWh
    int numberOfOccupants;

public:
    Building(double energy, int occupants) : energyConsumption(energy), numberOfOccupants(occupants) {}

    double calculateCarbonFootprint() const override {
        // Conversion factor: 0.029 tons of CO2 per kWh
        return energyConsumption * 0.029;
    }
};

class Car : public CarbonFootprint {
protected:
    double fuelConsumption; // in liters
    double fuelEfficiency; // in km per liter

public:
    Car(double consumption, double efficiency) : fuelConsumption(consumption), fuelEfficiency(efficiency) {}

    double calculateCarbonFootprint() const override {
        // Conversion factor: 2.31 kg of CO2 per liter of gasoline
        return fuelConsumption * fuelEfficiency * 2.31 / 100;
    }
};

class ElectricCar : public Car {
protected:
    double energyConsumption; // in kWh
    double chargeEfficiency;

public:
    ElectricCar(double energy, double efficiency) : Car(0, 0), energyConsumption(energy), chargeEfficiency(efficiency) {}

    double calculateCarbonFootprint() const override {
        // Conversion factor: 0.0145 tons of CO2 per kWh
        return (energyConsumption * chargeEfficiency * 0.000145) / 2;
    }
};

class Factory : public CarbonFootprint {
protected:
    double productionHours;
    double energyPerHour; // in kWh
    double wastePerHour; // in tons

public:
    Factory(double hours, double energy, double waste) : productionHours(hours), energyPerHour(energy), wastePerHour(waste) {}

    double calculateCarbonFootprint() const override {
        // Conversion factor: 0.029 tons of CO2 per kWh and 1.1 tons of CO2 per ton of waste
        return productionHours * (energyPerHour * 0.029 + wastePerHour * 1.1);
    }
};

class Bicycle : public CarbonFootprint {
protected:
    double manufacturingEmissions; // in kg

public:
    Bicycle(double emissions) : manufacturingEmissions(emissions) {}

    double calculateCarbonFootprint() const override {
        // Conversion factor: 0.00015 tons of CO2 per kg
        return manufacturingEmissions * 0.00015;
    }
};

int main() {
    std::vector<CarbonFootprint*> carbonFootprints;

    // User input for Building
    double buildingEnergy, buildingOccupants;
    std::cout << "Enter Building’s energy consumption (kWh) and number of occupants: ";
    std::cin >> buildingEnergy >> buildingOccupants;
    carbonFootprints.push_back(new Building(buildingEnergy, static_cast<int>(buildingOccupants)));

    // User input for Car
    double carConsumption, carEfficiency;
    std::cout << "Enter Car’s fuel consumption (liters) and fuel efficiency (km/liter): ";
    std::cin >> carConsumption >> carEfficiency;
    carbonFootprints.push_back(new Car(carConsumption, carEfficiency));

    // User input for Electric Car
    double electricCarEnergy, electricCarEfficiency;
    std::cout << "Enter Electric Car’s energy consumption (kWh), charge efficiency (ratio): ";
    std::cin >> electricCarEnergy >> electricCarEfficiency;
    carbonFootprints.push_back(new ElectricCar(electricCarEnergy, electricCarEfficiency));

    // Calculate and display carbon footprint for each object
    for (const auto& object : carbonFootprints) {
        std::cout << "Carbon Footprint: " << object->calculateCarbonFootprint() << " tons of CO2" << std::endl;
    }

    // Clean up allocated memory
    for (const auto& object : carbonFootprints) {
        delete object;
    }

    return 0;
}
