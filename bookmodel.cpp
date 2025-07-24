#include "bookmodel.h"

BookModel::BookModel(QVector<Book> &books, QObject *parent)
    : QAbstractTableModel(parent), bookList(books)
{
}

int BookModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return bookList.count();
}

int BookModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}

QVariant BookModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const Book &book = bookList[index.row()];
    switch (index.column()) {
    case 0: return book.id;
    case 1: return book.title;
    case 2: return book.author;
    case 3: return book.totalCopies;
    case 4: return book.availableCopies;
    default: return QVariant();
    }
}

QVariant BookModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return "ID";
        case 1: return "Title";
        case 2: return "Author";
        case 3: return "Total Copies";
        case 4: return "Available";
        }
    }
    return QVariant();
}

void BookModel::refresh()
{
    beginResetModel();
    endResetModel();
}
