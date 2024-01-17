#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_DISHES = 5;
const int NUM_POLLS = 5;
const int MAX_RATING = 10;

string dishes[NUM_DISHES] = {"Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", "Green Curry"};
int responses[NUM_DISHES][NUM_POLLS];

// Function to collect ratings from users in multiple polls
void collectRatings() {
    for (int poll = 0; poll < NUM_POLLS; ++poll) {
        cout << "Poll " << poll + 1 << " Ratings:" << endl;
        for (int dish = 0; dish < NUM_DISHES; ++dish) {
            do {
                cout << "Enter rating (1-10) for " << dishes[dish] << ": ";
                cin >> responses[dish][poll];

                // Validate the input
                if (responses[dish][poll] < 1 || responses[dish][poll] > MAX_RATING) {
                    cout << "Invalid rating. Please enter a rating between 1 and 10." << endl;
                }
            } while (responses[dish][poll] < 1 || responses[dish][poll] > MAX_RATING);
        }
    }
}

// Function to display results
void displayResults() {
    cout << "\nRating Summary:\n\n";
    cout << left << setw(30) << "Dish" << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\tAverage\n";

    for (int dish = 0; dish < NUM_DISHES; ++dish) {
        int totalPoints = 0;
        int ratingCounts[MAX_RATING + 1] = {0}; // To store counts for each rating

        cout << left << setw(30) << dishes[dish] << "\t";

        for (int poll = 0; poll < NUM_POLLS; ++poll) {
            // cout << responses[dish][poll] << "\t";
            totalPoints += responses[dish][poll];

            // Update the rating count
            ++ratingCounts[responses[dish][poll]];
        }

        // Calculate and display average
        double averageRating = static_cast<double>(totalPoints) / NUM_POLLS;

        // Display the count of each rating
        for (int rating = 1; rating <= MAX_RATING; ++rating) {
            cout << ratingCounts[rating] << "\t";
        }
        cout << averageRating << endl;
    }

    // Find and display the dish with the highest and lowest total points
    int highestTotalPoints = -1;
    int lowestTotalPoints = MAX_RATING * NUM_POLLS + 1;
    string highestDish, lowestDish;

    for (int dish = 0; dish < NUM_DISHES; ++dish) {
        int totalPoints = 0;

        for (int poll = 0; poll < NUM_POLLS; ++poll) {
            totalPoints += responses[dish][poll];
        }

        // Update highest and lowest dishes
        if (totalPoints > highestTotalPoints) {
            highestTotalPoints = totalPoints;
            highestDish = dishes[dish];
        }

        if (totalPoints < lowestTotalPoints) {
            lowestTotalPoints = totalPoints;
            lowestDish = dishes[dish];
        }
    }

    cout << "\nMost Popular Dish: " << highestDish << " (" << highestTotalPoints << " points)" << endl;
    cout << "Least Popular Dish: " << lowestDish << " (" << lowestTotalPoints << " points)" << endl;
}

int main() {
    // Collect ratings from users
    collectRatings();

    // Display results
    displayResults();

    return 0;
}
