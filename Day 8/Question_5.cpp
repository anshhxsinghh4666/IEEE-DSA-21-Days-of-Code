/*
"Problem Statement:
Scenario:
You are tasked with developing a menu-driven program for a small library management system. The program should allow users to perform various operations such as adding a book, searching for a book by its ID, deleting a book by its ID, displaying all books, and exiting the program.

Input:
The program will repeatedly display a menu with the following options:

Add a book
Search for a book by ID
Delete a book by ID
Display all books
Exit
For Option 1 (Add a book): The user will input a book ID (integer) and a book title (string).
For Option 2 (Search for a book by ID): The user will input the book ID to search for.
For Option 3 (Delete a book by ID): The user will input the book ID to delete.
For Option 4 (Display all books): The program will display all the books currently in the system.
For Option 5 (Exit): The program will terminate.

Output:

For Option 1: The program should confirm that the book was added.
For Option 2: The program should display the book details if found or notify the user if the book is not found.
For Option 3: The program should confirm that the book was deleted or notify the user if the book ID is not found.
For Option 4: The program should list all books in the system.
For Option 5: The program will exit with a message.

Constraints:

The system can hold a maximum of 100 books.
The book ID must be unique.
The title should not exceed 50 characters.
Input validation should be performed for book ID to ensure it is a positive integer.

Example:
Input:
1. Add a book
2. Search for a book by ID
3. Delete a book by ID
4. Display all books
5. Exit

Choose an option: 1
Enter Book ID: 101
Enter Book Title: ""C Programming Language""

Choose an option: 1
Enter Book ID: 102
Enter Book Title: ""Data Structures in C""

Choose an option: 2
Enter Book ID: 101

Choose an option: 4

Choose an option: 3
Enter Book ID: 102

Choose an option: 5

Output:
Book added successfully.
Book added successfully.
Book found: ID=101, Title=""C Programming Language""
Book ID=101, Title=""C Programming Language""
Book deleted successfully.
Exiting the program...

Explanation:

The user adds two books with IDs 101 and 102. Program usually confirms the addition of each book.
The user searches for the book with ID 101, and the program displays its details.
The user displays all books, and the program lists the available book.
The user deletes the book with ID 102, and the program confirms the deletion.
The user exits the program."

*/


#include <iostream>
#include <string>
#include <vector>
#include <limits> // for numeric_limits

using namespace std;

class Book {
private:
    int id;
    string title;

public:
    Book(int id, const string& title) : id(id), title(title) {}

    int getId() const { return id; }
    string getTitle() const { return title; }

    void display() const {
        cout << "Book ID=" << id << ", Title=\"" << title << "\"" << endl;
    }
};

class Library {
private:
    vector<Book> books;
    static const int MAX_BOOKS = 100;

public:
    void addBook() {
        if (books.size() >= MAX_BOOKS) {
            cout << "Library is full, cannot add more books." << endl;
            return;
        }

        int id;
        string title;

        cout << "Enter Book ID: ";
        cin >> id;

        // Input validation for positive integer
        if (id <= 0) {
            cout << "Book ID must be a positive integer. Book not added." << endl;
            return;
        }

        // Check for unique ID
        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "Book ID must be unique. Book not added." << endl;
                return;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "Enter Book Title: ";
        getline(cin, title);

        if (title.length() > 50) {
            cout << "Title should not exceed 50 characters. Book not added." << endl;
            return;
        }

        books.emplace_back(id, title);
        cout << "Book added successfully." << endl;
    }

    void searchBookById() const {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;

        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "Book found: ";
                book.display();
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void deleteBookById() {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Book deleted successfully." << endl;
                return;
            }
        }
        cout << "Book ID not found." << endl;
    }

    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }

        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\n1. Add a book\n";
        cout << "2. Search for a book by ID\n";
        cout << "3. Delete a book by ID\n";
        cout << "4. Display all books\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.searchBookById();
                break;
            case 3:
                library.deleteBookById();
                break;
            case 4:
                library.displayAllBooks();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid option. Please choose again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}