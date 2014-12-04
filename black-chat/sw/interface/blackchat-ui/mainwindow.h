#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_btnClear_clicked();

    void on_plainTextEdit_cursorPositionChanged();

    void on_btnKeyGen_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
