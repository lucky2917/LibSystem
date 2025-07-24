#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QMainWindow>
#include "library.h"
#include "bookmodel.h"

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminDashboard(Library *lib, QWidget *parent = nullptr);
    ~AdminDashboard();

private slots:
    void on_addBookButton_clicked();
    void on_editBookButton_clicked(); // <-- Added slot
    void on_removeBookButton_clicked();

private:
    Ui::AdminDashboard *ui;
    Library *library;
    BookModel *bookModel;
};

#endif // ADMINDASHBOARD_H
