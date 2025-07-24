#include "customerdashboard.h"
#include "ui_customerdashboard.h"
#include <QHeaderView>
#include <QMessageBox>

CustomerDashboard::CustomerDashboard(Library *lib, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerDashboard),
    library(lib)
{
    ui->setupUi(this);

    bookModel = new BookModel(library->bookList, this);
    ui->tableView->setModel(bookModel);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

CustomerDashboard::~CustomerDashboard()
{
    delete ui;
}

void CustomerDashboard::on_borrowButton_clicked()
{
    // 1. Get the selected row from the table
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select a book to borrow.");
        return;
    }

    int rowIndex = selection.first().row();

    // 2. Call the library's borrow function
    if (library->borrowBook(rowIndex)) {
        // If successful, show a success message and update the table
        QMessageBox::information(this, "Success", "You have successfully borrowed the book!");
        bookModel->refresh();
    } else {
        // If it fails, it means the book is out of stock
        QMessageBox::critical(this, "Out of Stock", "Sorry, there are no available copies of this book.");
    }
}
