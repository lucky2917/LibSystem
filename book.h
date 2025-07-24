#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();

    int id;
    QString title;
    QString author;
    int totalCopies;
    int availableCopies;
};

#endif // BOOK_H
