#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    std::cout << ui->plainTextEdit->toPlainText().toUtf8().constData() << std::endl;
}

void MainWindow::on_btnClear_clicked()
{
    ui->txtMessage->clear();
}
