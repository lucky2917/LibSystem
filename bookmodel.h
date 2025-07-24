#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "book.h"

class BookModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BookModel(QVector<Book> &books, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void refresh();

private:
    QVector<Book> &bookList;
};

#endif // BOOKMODEL_H
