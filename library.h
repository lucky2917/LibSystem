#ifndef LIBRARY_H
#define LIBRARY_H

#include <QVector>
#include "book.h"
#include "user.h"

class Library
{
public:
    Library();

    QVector<Book> bookList;
    QVector<User> userList;

    // Function declarations
    User::UserType validateUser(const QString& username, const QString& password);
    void addBook(const Book& book);
    void removeBook(int rowIndex);
    void updateBook(int rowIndex, const Book& updatedBook);
    bool borrowBook(int rowIndex); // <-- Added function
};

#endif // LIBRARY_H
