#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book
{
private:
    string title;
    string author;
    int quantity;
public:
    Book(string inputTitle, string inputAuthor, int inputQuantity) : title(inputTitle), author(inputAuthor), quantity(inputQuantity)
    {

    }

    void setTitle(string inputTitle)
    {
        title = inputTitle;
    }

    void setAuthor(string inputAuthor)
    {
        author = inputAuthor;
    }

    void setQuantity(int inputQuantity)
    {
        quantity = inputQuantity;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    int getQuantity()
    {
        return quantity;
    }
};

class Inventory
{
private:
    vector<Book> books;
public:
    Inventory()
    {

    }

    void addBook(string inputBookTitle, string inputBookAuthor, int inputBookQuantity)
    {
        string upperinputbooktitle = inputBookTitle;
        transform(upperinputbooktitle.begin(),upperinputbooktitle.end(),upperinputbooktitle.begin(),[](char c){return toupper(c);});
        Book bookObject(upperinputbooktitle, inputBookAuthor, inputBookQuantity);
        books.push_back(bookObject);
    }

    void removeBook(string inputBookTitle)
    {
        for (auto element = books.begin(); element != books.end(); ++element)
        {
            if (element -> getTitle() == inputBookTitle)
            {
                books.erase(element);
                return;
            }
            
        }
        
    }

    Book findBook(string inputBookTitle)
    {
        for (auto& book : books) {
            if (book.getTitle() == inputBookTitle) {
                return book;
            }
        }
        return Book("", "", 0);
        // return nullptr;
    }

    void printInventory()
    {
        for (Book element : books)
        {
            cout << "Title : " << element.getTitle() << ", Author : " << element.getAuthor() << ", Quantity : " << element.getQuantity() << endl;
        }
    }
};

int main()
{
    Inventory inventory;
    char command;
    string title, author;
    int quantity;

    while (true)
    {
        cout << "Enter command (a: add, r: remove, s: search, l: list, q: quit): ";
        cin >> command;

        if (command == 'a')
        {
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter Author: ";
            cin >> author;
            cout << "Enter Quantity: ";
            cin >> quantity;
            inventory.addBook(title, author, quantity);
        }
        else if (command == 's')
        {
            cout << "Enter title: ";
            cin >> title;
            Book result = inventory.findBook(title);
            if (result.getAuthor() != "" && result.getTitle() != "" && result.getQuantity() != 0)
            {
                cout << "Founded : " << result.getAuthor() << result.getTitle() << result.getQuantity();
            }
            else
            {
                cout << "Not Founded";
            }
            
        }
        else if (command == 'l')
        {
            inventory.printInventory();
        }
        
        else if (command == 'q')
        {
            break;
        }
        
        
    }

    // title = "Hey Jude";
    // author = "Jude Bellingham";
    // quantity = 5;

    // inventory.addBook(title, author, quantity);
    // inventory.addBook(title, author, quantity);
    // inventory.printInventory();
    // inventory.removeBook(title);
    // Book resultBook = inventory.findBook(title);
    // cout << "Founded Title: " << resultBook.getTitle() << ", Author: " << resultBook.getAuthor() << ", Quantity: " << resultBook.getQuantity() << endl;
    // inventory.printInventory();
    return 0;
}
