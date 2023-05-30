#include <iostream>
#include <vector>
#include <string>

using namespace std;

// creating a structure to represent a book
struct Book {
    string title; // title for the book
    string author; // author for the book
    int year; // published year of the book

    void displayDetails() {
        cout << "Title: " << title << endl; // displaying title details of the book
        cout << "Author: " << author << endl; // displaying the author details of the book
        cout << "Year: " << year << endl; // displaying the publishing year of the book
    }
};

// Function to add a book to the library
void addBook(vector<Book>& library) {
    Book book; // creating object for the structure
    cout << "Enter book title: "; // getting input from user for the title of the book
    getline(cin >> ws, book.title); // using getline for getting the input from user as a string
    cout << "Enter author: "; // getting input from user for the author of the book
    getline(cin >> ws, book.author); // using getline for getting the input from user as a string
    cout << "Enter publication year: "; // getting input from user for the publication year of the book
    cin >> book.year; // since it is integer we are doing normal cin
    library.push_back(book); // we are pushing back the book structure to the vector library 
    // the structure of the vector would be {{title,author,publishing year}}
    cout << "Book added!" << endl; // printing the book has been added to the library
}

// Function to display all the books in the library
void displayBooks(const vector<Book>& library) {
    if (library.empty()) { // if the book is empty means the library vector is empty
        cout << "Library is empty." << endl; // prints library is empty
        return;
    }
    // else printing the books in the library
    cout << "Library books:" << endl;
    for (const auto& book : library) { // iterating over the vector
        cout << "---------------------------" << endl;
        cout << "Title: " << book.title << endl; // printing the title of the book
        cout << "Author: " << book.author << endl; // printing the author of the book
        cout << "Year: " << book.year << endl;  // printing the publishing year of the book
    }
    cout << "---------------------------" << endl;
}

// Main function
int main() {
    vector<Book> library;
    int choice;
    // creating switchcase for the user to either create a book or display book or exit the program in a while loop so that it will go
    // untill the user stops
    while (true) {
        // printing the options available for the user
        cout << "Menu:" << endl; 
        cout << "1. Add book" << endl;
        cout << "2. Display books" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        // after getting the choice from user asking for the choice
        cin >> choice; 
        // mapping the above function using switch case
        switch (choice) {
            case 1:
                // 1 is add book mapping the users input to addbook function which will add book to the library vector
                addBook(library);
                break;
            case 2:
                // 2 means displaying the book which will display book to the user passing the vector library as parameter 
                displayBooks(library);
                break;
            case 3:
                // 3 means exiting the program if user wants to exit he can
                cout << "Exiting program." << endl;
                // returning 0 to stop the code running on command line interface
                return 0;
            default:
                // if any options other than this means it is invalid he has to try again
                cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
