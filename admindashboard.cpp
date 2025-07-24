#include "admindashboard.h"
#include "ui_admindashboard.h"
#include "addbookdialog.h"
#include <QMessageBox>
#include <QHeaderView> // <-- Include for resizing columns

AdminDashboard::AdminDashboard(Library *lib, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminDashboard),
    library(lib)
{
    ui->setupUi(this);

    bookModel = new BookModel(library->bookList, this);
    ui->tableView->setModel(bookModel);

    // This line stretches the columns to fit the window width
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

void AdminDashboard::on_addBookButton_clicked()
{
    AddBookDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Book newBook = dialog.getBookData();
        library->addBook(newBook);
        bookModel->refresh();
    }
}

void AdminDashboard::on_editBookButton_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select a book to edit.");
        return;
    }

    int rowIndex = selection.first().row();
    Book selectedBook = library->bookList.at(rowIndex);

    AddBookDialog dialog(this);
    dialog.setWindowTitle("Edit Book");
    dialog.setBookData(selectedBook);

    if (dialog.exec() == QDialog::Accepted) {
        Book updatedBook = dialog.getBookData();
        library->updateBook(rowIndex, updatedBook);
        bookModel->refresh();
    }
}

void AdminDashboard::on_removeBookButton_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select a book to remove.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Remove", "Are you sure you want to remove this book?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        int rowIndex = selection.first().row();
        library->removeBook(rowIndex);
        bookModel->refresh();
    }
}
