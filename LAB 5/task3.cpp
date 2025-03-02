# include <iostream>
# include<string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    string getISBN() const {
        return isbn;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }
};

class Catalog {
private:
    Book* books[10]; 
    int bookCount;

public:
    Catalog() : bookCount(0) {}

    void addBook(Book* book) {
        if (bookCount < 10) {
            books[bookCount++] = book;
        } else {
            cout << "Catalog is full!" << endl;
        }
    }

    void findBook(const string& isbn) const {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->getISBN() == isbn) {
                cout << "Book found: " << books[i]->getTitle() << endl;
                return;
            }
        }
        cout << "Book not found in catalog." << endl;
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog; 

public:
    Library(string n, string a) : name(n), address(a) {}

    void addBook(Book* book) {
        catalog.addBook(book);
    }

    void findBookInCatalog(const string& isbn) const {
        catalog.findBook(isbn);
    }
};

int main() {
    Library myLibrary("City Library", "123 Main St");
    
    Book book1("C++ Primer", "Lippman", "12345");
    Book book2("Effective C++", "Scott Meyers", "67890");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.findBookInCatalog("12345");
    myLibrary.findBookInCatalog("67890");
    myLibrary.findBookInCatalog("00000"); 

    return 0;
}

