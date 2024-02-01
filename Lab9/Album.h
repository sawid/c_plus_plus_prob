#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <vector>

class Album {
private:
    std::string title;
    std::string artist;
    double price;
    int copiesAvailable;

    static int totalAlbums;
    static double totalSales;

public:
    Album(const std::string& title, const std::string& artist, double price, int copies);

    void purchaseAlbum();

    static int getTotalAlbums();
    static double getTotalSales();

    std::string getTitle() const;
    std::string getArtist() const;
    double getPrice() const;
    int getCopiesAvailable() const;
};

#endif
