#include <iostream>
#include <vector>
#include <iomanip>

struct Movie {
    std::string title;
    std::string date;
    std::vector<std::vector<bool>> availableSeats;
};

struct Reservation {
    std::string customerName;
    std::string movieTitle;
    std::string date;
    int round;
    int seatNumber;
};

void displaySchedule(const std::vector<Movie>& movies) {
    for (const auto& movie : movies) {
        std::cout << "Movie: " << movie.title << "\nDate: " << movie.date;

        for (int i = 0; i < 4; ++i) {
            std::cout << "  Round " << i + 1 << ": " << std::count(movie.availableSeats[i].begin(), movie.availableSeats[i].end(), true) << " seats left";
        }

        std::cout << "\n";
    }
}

bool isSeatAvailable(const Movie& movie, int round, int seatNumber) {
    return movie.availableSeats[round - 1][seatNumber - 1];
}

void makeReservation(std::vector<Movie>& movies) {
    std::string customerName;
    int movieIndex, dateIndex, round, seatNumber;

    displaySchedule(movies);

    std::cout << "Select a movie:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        std::cout << i + 1 << ") " << movies[i].title << "\n";
    }
    std::cout << "Enter movie number: ";
    std::cin >> movieIndex;
    movieIndex--;  // Adjust for zero-based indexing

    std::cout << "Select a date:\n";
    for (size_t i = 0; i < movies[movieIndex].availableSeats.size(); ++i) {
        std::cout << i + 1 << ") " << movies[movieIndex].date << "\n";
    }
    std::cout << "Enter date number: ";
    std::cin >> dateIndex;
    dateIndex--;  // Adjust for zero-based indexing

    std::cout << "Select a round:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << i + 1 << ") Round " << i + 1 << " - " << std::count(movies[movieIndex].availableSeats[i].begin(), movies[movieIndex].availableSeats[i].end(), true) << " seats left\n";
    }
    std::cout << "Enter round number: ";
    std::cin >> round;

    std::cout << "Enter the number of seats to reserve: ";
    std::cin >> seatNumber;

    if (!isSeatAvailable(movies[movieIndex], round, seatNumber)) {
        std::cout << "Invalid input. The seat is not available.\n";
        return;
    }

    Reservation reservation;
    reservation.customerName = customerName;
    reservation.movieTitle = movies[movieIndex].title;
    reservation.date = movies[movieIndex].date;
    reservation.round = round;
    reservation.seatNumber = seatNumber;

    // Update availableSeats
    movies[movieIndex].availableSeats[round - 1][seatNumber - 1] = false;

    std::cout << "Successfully reserved " << seatNumber << " seat(s) for " << reservation.movieTitle
              << " on " << reservation.date << " for round " << reservation.round << ".\n";
}

int main() {
    std::vector<Movie> movies = {
        {"Poor Things", "2024-03-01", std::vector<std::vector<bool>>(4, std::vector<bool>(10, true))},
        {"เหมรย", "2024-03-01", std::vector<std::vector<bool>>(4, std::vector<bool>(10, true))},
        {"4KingsII", "2024-03-01", std::vector<std::vector<bool>>(4, std::vector<bool>(10, true))}
    };

    int choice;

    do {
        std::cout << "1. View Schedule\n2. Make Reservation\n3. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displaySchedule(movies);
                break;
            case 2:
                makeReservation(movies);
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    } while (choice != 3);

    return 0;
}
