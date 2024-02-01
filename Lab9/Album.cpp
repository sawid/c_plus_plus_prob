#include "Album.h"
#include <iostream>

int Album::totalAlbums = 0;
double Album::totalSales = 0;

Album::Album(const std::string& title, const std::string& artist, double price, int copies)
    : title(title), artist(artist), price(price), copiesAvailable(copies) {
    totalAlbums += copies;
}

void Album::purchaseAlbum() {
    if (copiesAvailable > 0) {
        copiesAvailable--;
        totalSales += price;
        std::cout << "Album purchased: " << title << " by " << artist << std::endl;
    } else {
        std::cout << "Sorry, the album " << title << " by " << artist << " is out of stock." << std::endl;
    }
}

int Album::getTotalAlbums() {
    return totalAlbums;
}

double Album::getTotalSales() {
    return totalSales;
}

std::string Album::getTitle() const {
    return title;
}

std::string Album::getArtist() const {
    return artist;
}

double Album::getPrice() const {
    return price;
}

int Album::getCopiesAvailable() const {
    return copiesAvailable;
}
