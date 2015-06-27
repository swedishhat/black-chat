#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdlib.h>

bool plainTextEdit_first_clicked = true;
int secretKey[8] = {0,0,0,0,0,0,0,0};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString welcome = "Welcome to BlackChat.";
    QString startkey = "No Key Generated";

    ui->setupUi(this);
    ui->txtKeyBox->text() = startkey;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClear_clicked()
{
    std::cout << ui->txtMessage->toPlainText().toUtf8().constData() << std::endl;
    ui->txtMessage->clear();
}

void MainWindow::on_plainTextEdit_cursorPositionChanged()
{
}

void MainWindow::on_btnKeyGen_clicked()
{

    for(int i =0; i < 8; i++){
        secretKey[i] = rand() % 16; //Random hex number
    }

}
