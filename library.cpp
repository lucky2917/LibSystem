#include "library.h"

Library::Library()
{
    // --- Create a default Admin User ---
    User adminUser;
    adminUser.id = 1;
    adminUser.username = "admin";
    adminUser.password = "admin123";
    adminUser.type = User::ADMIN;
    userList.append(adminUser);

    // --- Create a default Customer User ---
    User customerUser;
    customerUser.id = 2;
    customerUser.username = "customer";
    customerUser.password = "pass";
    customerUser.type = User::CUSTOMER;
    userList.append(customerUser);

    // --- Create the default list of 8 books ---
    Book book;
    book.id = 101; book.title = "Through my window"; book.author = "Ariana Godoy"; book.totalCopies = 5; book.availableCopies = 5;
    bookList.append(book);
    book.id = 102; book.title = "10 Things I Hate About You"; book.author = "Karen McCullah"; book.totalCopies = 4; book.availableCopies = 3;
    bookList.append(book);
    book.id = 103; book.title = "After"; book.author = "Anna Todd"; book.totalCopies = 6; book.availableCopies = 6;
    bookList.append(book);
    book.id = 104; book.title = "Culpa Mia"; book.author = "Mercedes Ron"; book.totalCopies = 3; book.availableCopies = 2;
    bookList.append(book);
    book.id = 105; book.title = "Five Feet Apart"; book.author = "Rachael Lippincott"; book.totalCopies = 5; book.availableCopies = 5;
    bookList.append(book);
    book.id = 106; book.title = "La La Land"; book.author = "Damien Chazelle"; book.totalCopies = 2; book.availableCopies = 1;
    bookList.append(book);
    book.id = 107; book.title = "The Girl Next Door"; book.author = "Jack Ketchum"; book.totalCopies = 4; book.availableCopies = 4;
    bookList.append(book);
    book.id = 108; book.title = "The Kissing Booth"; book.author = "Beth Reekles"; book.totalCopies = 7; book.availableCopies = 7;
    bookList.append(book);
}

User::UserType Library::validateUser(const QString& username, const QString& password)
{
    for (const User& user : userList) {
        if (user.username == username && user.password == password) {
            return user.type;
        }
    }
    return User::INVALID;
}

void Library::addBook(const Book& book)
{
    Book newBook = book;
    newBook.id = bookList.isEmpty() ? 101 : bookList.last().id + 1;
    bookList.append(newBook);
}

void Library::removeBook(int rowIndex)
{
    if (rowIndex >= 0 && rowIndex < bookList.size()) {
        bookList.remove(rowIndex);
    }
}

void Library::updateBook(int rowIndex, const Book& updatedBook)
{
    if (rowIndex >= 0 && rowIndex < bookList.size()) {
        int oldTotal = bookList[rowIndex].totalCopies;
        int oldAvailable = bookList[rowIndex].availableCopies;
        bookList[rowIndex].title = updatedBook.title;
        bookList[rowIndex].author = updatedBook.author;
        bookList[rowIndex].totalCopies = updatedBook.totalCopies;
        int diff = updatedBook.totalCopies - oldTotal;
        bookList[rowIndex].availableCopies = oldAvailable + diff;
        if (bookList[rowIndex].availableCopies < 0) {
            bookList[rowIndex].availableCopies = 0;
        }
    }
}

bool Library::borrowBook(int rowIndex)
{
    if (rowIndex >= 0 && rowIndex < bookList.size()) {
        // Check if there are copies available
        if (bookList[rowIndex].availableCopies > 0) {
            bookList[rowIndex].availableCopies--; // Decrease the count
            return true; // Success
        }
    }
    return false; // Failed (either bad index or no copies available)
}
