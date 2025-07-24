#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "admindashboard.h"
#include "customerdashboard.h"
#include "user.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    User::UserType userType = library.validateUser(username, password);

    if (userType == User::ADMIN) {
        hide();
        AdminDashboard *adminView = new AdminDashboard(&library, this);
        adminView->show();
    } else if (userType == User::CUSTOMER) {
        hide();
        CustomerDashboard *customerView = new CustomerDashboard(&library, this);
        customerView->show();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
