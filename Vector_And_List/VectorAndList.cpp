#include <iostream>
#include <vector>
#include <list>

class Book {
public:
    Book(const std::string& title) : title(title) {}

    const std::string& getTitle() const {
        return title;
    }

private:
    std::string title;
};

int main() {
    // Characteristic 1: Underlying Data Structure
    std::cout << "Characteristic 1: Underlying Data Structure\n";
    std::vector<Book> vectorOfBooks;
    std::list<Book> listOfBooks;

    // Characteristic 2: Insertion and Removal
    std::cout << "\nCharacteristic 2: Insertion and Removal\n";
    vectorOfBooks.push_back(Book("Book1"));
    vectorOfBooks.push_back(Book("Book2"));
    vectorOfBooks.push_back(Book("Book3"));
    
    auto vectorIt = vectorOfBooks.begin();
    ++vectorIt; // Move to the second element
    vectorOfBooks.insert(vectorIt, Book("InsertedBook"));

    listOfBooks.push_back(Book("Book1"));
    listOfBooks.push_back(Book("Book2"));
    listOfBooks.push_back(Book("Book3"));

    auto listIt = ++listOfBooks.begin(); // Move to the second element
    listOfBooks.insert(listIt, Book("InsertedBook"));

    // Characteristic 3: Random Access
    std::cout << "\nCharacteristic 3: Random Access\n";
    std::cout << "First book in vector: " << vectorOfBooks[0].getTitle() << std::endl;
    
    auto vectorRandomAccessIt = vectorOfBooks.begin() + 2; // Move to the third element
    std::cout << "Third book in vector: " << (*vectorRandomAccessIt).getTitle() << std::endl;

    // Note: Lists do not support random access with 'operator[]'

    // Characteristic 4: Memory Allocation
    std::cout << "\nCharacteristic 4: Memory Allocation\n";
    // Not explicitly shown in the example, but vectors allocate a single contiguous block
    // Lists allocate separate nodes, which may lead to potential memory fragmentation

    // Characteristic 5: Memory Overhead
    std::cout << "\nCharacteristic 5: Memory Overhead\n";
    std::cout << "Size of vector: " << sizeof(vectorOfBooks) << " bytes" << std::endl;
    std::cout << "Size of list: " << sizeof(listOfBooks) << " bytes" << std::endl;

    // Characteristic 6: Iterator Validity
    std::cout << "\nCharacteristic 6: Iterator Validity\n";
    auto vectorEraseIt = vectorOfBooks.begin() + 1; // Erase the second element
    vectorOfBooks.erase(vectorEraseIt);

    auto listEraseIt = ++listOfBooks.begin(); // Erase the second element
    listOfBooks.erase(listEraseIt);

    // Note: Iterators remain valid after erasure for lists and vectors

    // Characteristic 7: Use Cases
    std::cout << "\nCharacteristic 7: Use Cases\n";
    // Vectors: Suitable for scenarios where random access is important
    // Lists: Suitable for scenarios with frequent insertions and removals at various positions

    return 0;
}
