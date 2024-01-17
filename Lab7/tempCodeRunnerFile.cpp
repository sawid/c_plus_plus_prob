#include <iostream>
#include <string>

using namespace std;

const int NUM_DISHES = 5;
const int NUM_POLLS = 5;
const int MAX_RATING = 10;

string dishes[NUM_DISHES] = {"Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", "Green Curry"};
int responses[NUM_DISHES][NUM_POLLS] = {0}; // Initialize to all zeros

// Function to collect ratings from users in multiple polls
void collectRatings()
{
    for (int i = 0; i < NUM_DISHES; ++i)
    {
        cout << "Enter ratings for " << dishes[i] << " (1-10) in 5 separate polls:" << endl;

        for (int j = 0; j < NUM_POLLS; ++j)
        {
            do
            {
                cout << "Poll " << j + 1 << ": ";
                cin >> responses[i][j];

                // Validate the input
                if (responses[i][j] < 0 || responses[i][j] > MAX_RATING)
                {
                    cout << "Invalid rating. Please enter a rating between 0 and 10." << endl;
                }
            } while (responses[i][j] < 0 || responses[i][j] > MAX_RATING);
        }
    }
}

// Function to display results
void displayResults()
{
    // Display header
    cout << "\nRating Summary:\n\n";
    cout << "Dish\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\tAverage\n";

    // Display ratings and calculate averages
    for (int i = 0; i < NUM_DISHES; ++i)
    {
        int totalPoints = 0;

        cout << dishes[i] << "\t";

        for (int j = 0; j < NUM_POLLS; ++j)
        {
            cout << responses[i][j] << "\t";
            totalPoints += responses[i][j];
        }

        // Calculate and display average
        double averageRating = (totalPoints == 0) ? 0 : static_cast<double>(totalPoints) / NUM_POLLS;
        cout << averageRating << endl;
    }

    // Find and display the dish with the highest and lowest total points
    int highestTotalPoints = -1;
    int lowestTotalPoints = MAX_RATING * NUM_POLLS + 1;
    string highestDish, lowestDish;

    for (int i = 0; i < NUM_DISHES; ++i)
    {
        int totalPoints = 0;

        for (int j = 0; j < NUM_POLLS; ++j)
        {
            totalPoints += responses[i][j];
        }

        // Update highest and lowest dishes
        if (totalPoints > highestTotalPoints)
        {
            highestTotalPoints = totalPoints;
            highestDish = dishes[i];
        }

        if (totalPoints < lowestTotalPoints)
        {
            lowestTotalPoints = totalPoints;
            lowestDish = dishes[i];
        }
    }

    cout << "\nMost Popular Dish: " << highestDish << " (" << highestTotalPoints << " points)" << endl;
    cout << "Least Popular Dish: " << lowestDish << " (" << lowestTotalPoints << " points)" << endl;
}

int main()
{
    // Collect ratings from users
    collectRatings();

    // Display results
    displayResults();

    return 0;
}
