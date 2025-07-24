#ifndef CUSTOMERDASHBOARD_H
#define CUSTOMERDASHBOARD_H

#include <QMainWindow>
#include "library.h"
#include "bookmodel.h"

namespace Ui {
class CustomerDashboard;
}

class CustomerDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerDashboard(Library *lib, QWidget *parent = nullptr);
    ~CustomerDashboard();

private slots:
    void on_borrowButton_clicked();

private:
    Ui::CustomerDashboard *ui;
    Library *library;
    BookModel *bookModel;
};

#endif // CUSTOMERDASHBOARD_H
