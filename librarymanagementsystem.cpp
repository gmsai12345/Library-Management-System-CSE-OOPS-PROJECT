#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    int year;

    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

// Function to add a book to the library
void addBook(vector<Book>& library) {
    Book book;
    cout << "Enter book title: ";
    getline(cin >> ws, book.title);
    cout << "Enter author: ";
    getline(cin >> ws, book.author);
    cout << "Enter publication year: ";
    cin >> book.year;
    library.push_back(book);
    cout << "Book added!" << endl;
}

// Function to display all the books in the library
void displayBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "Library is empty." << endl;
        return;
    }
    cout << "Library books:" << endl;
    for (const auto& book : library) {
        cout << "---------------------------" << endl;
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Year: " << book.year << endl;
    }
    cout << "---------------------------" << endl;
}

// Main function
int main() {
    vector<Book> library;
    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Display books" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();  // Ignore any remaining newline characters
                addBook(library);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
