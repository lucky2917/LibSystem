#include "addbookdialog.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

Book AddBookDialog::getBookData() const
{
    Book newBook;
    newBook.title = ui->titleLineEdit->text();
    newBook.author = ui->authorLineEdit->text();
    newBook.totalCopies = ui->copiesLineEdit->text().toInt();
    newBook.availableCopies = newBook.totalCopies; // This logic might need adjustment for edits
    return newBook;
}

void AddBookDialog::setBookData(const Book& book)
{
    // Set the text for each input field
    ui->titleLineEdit->setText(book.title);
    ui->authorLineEdit->setText(book.author);
    ui->copiesLineEdit->setText(QString::number(book.totalCopies));
}
