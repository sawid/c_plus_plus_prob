#include <iostream>

class SetProcessor {
public:
    virtual void processSet(int setId) const = 0;
};

class SumCalculator : public SetProcessor {
public:
    void processSet(int setId) const override {
        // Set specific start and end values
        int start = setId * 10 - 9;
        int end = setId * 10;
        int sum = 0;

        // Loop through each number in the set, add it to sum
        for (int i = start; i <= end; ++i) {
            sum += i;
        }

        // Output the sum for the set
        std::cout << "Sum of Set " << setId << ": " << sum << std::endl;
    }
};

int main() {
    // Create an instance of SetProcessor (polymorphic behavior).
    SetProcessor* setProcessor = new SumCalculator();

    // Process each set using the polymorphic behavior
    for (int setId = 1; setId <= 10; ++setId) {
        setProcessor->processSet(setId);
    }

    // Clean up allocated memory.
    delete setProcessor;

    return 0;
}
