#include <iostream>
#include <vector>
#include "Album.h"

void displayMenu() {
    std::cout << "\nOnline Music Store Menu:\n";
    std::cout << "1. List all albums\n";
    std::cout << "2. Purchase an album\n";
    std::cout << "3. Display sales statistics\n";
    std::cout << "4. Exit\n";
}

int main() {
    std::vector<Album> albums;
    albums.emplace_back("Abbey Road", "The Beatles", 19.99, 5);
    albums.emplace_back("The Dark Side of the Moon", "Pink Floyd", 21.99, 3);
    albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
    albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);
    albums.emplace_back("Rumours", "Fleetwood Mac", 16.99, 3);
    albums.emplace_back("Thriller", "Michael Jackson", 18.99, 5);
    albums.emplace_back("The Wall", "Pink Floyd", 22.99, 2);
    albums.emplace_back("Led Zeppelin IV", "Led Zeppelin", 17.99, 3);

    while (true) {
        displayMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nAvailable Albums:\n";
                for (size_t i = 0; i < albums.size(); ++i) {
                    std::cout << i + 1 << ". " << albums[i].getTitle() << " by " << albums[i].getArtist()
                              << " - $" << albums[i].getPrice() << " (" << albums[i].getCopiesAvailable()
                              << " copies available)\n";
                }
                break;
            case 2:
                std::cout << "Enter the index of the album you want to purchase: ";
                int index;
                std::cin >> index;
                if (index >= 1 && static_cast<size_t>(index) <= albums.size()) {
                    albums[index - 1].purchaseAlbum();
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            case 3:
                std::cout << "Total albums in inventory: " << Album::getTotalAlbums() << std::endl;
                std::cout << "Total sales made: $" << Album::getTotalSales() << std::endl;
                break;
            case 4:
                std::cout << "Thank you for using the Online Music Store.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
