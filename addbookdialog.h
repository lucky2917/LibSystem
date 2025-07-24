#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include "book.h"

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBookDialog(QWidget *parent = nullptr);
    ~AddBookDialog();

    // Gets book data from the dialog's fields
    Book getBookData() const;

    // Sets the dialog's fields with existing book data (for editing)
    void setBookData(const Book& book);

private:
    Ui::AddBookDialog *ui;
};

#endif // ADDBOOKDIALOG_H
