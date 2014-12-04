/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboDevSelect;
    QPushButton *btnDevRefresh;
    QPushButton *btnDevConnect;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *txtKeyBox;
    QPushButton *btnKeyGen;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *txtDebug;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *txtConversation;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnClear;
    QPushButton *btnSend;
    QPlainTextEdit *txtMessage;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *lblCharCount;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboDevSelect = new QComboBox(centralwidget);
        comboDevSelect->setObjectName(QStringLiteral("comboDevSelect"));

        horizontalLayout->addWidget(comboDevSelect);

        btnDevRefresh = new QPushButton(centralwidget);
        btnDevRefresh->setObjectName(QStringLiteral("btnDevRefresh"));

        horizontalLayout->addWidget(btnDevRefresh);

        btnDevConnect = new QPushButton(centralwidget);
        btnDevConnect->setObjectName(QStringLiteral("btnDevConnect"));

        horizontalLayout->addWidget(btnDevConnect);


        horizontalLayout_5->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 2, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        txtKeyBox = new QLineEdit(centralwidget);
        txtKeyBox->setObjectName(QStringLiteral("txtKeyBox"));
        txtKeyBox->setReadOnly(true);

        horizontalLayout_4->addWidget(txtKeyBox);

        btnKeyGen = new QPushButton(centralwidget);
        btnKeyGen->setObjectName(QStringLiteral("btnKeyGen"));

        horizontalLayout_4->addWidget(btnKeyGen);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        txtDebug = new QTextBrowser(centralwidget);
        txtDebug->setObjectName(QStringLiteral("txtDebug"));

        horizontalLayout_3->addWidget(txtDebug);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        txtConversation = new QTextBrowser(centralwidget);
        txtConversation->setObjectName(QStringLiteral("txtConversation"));

        verticalLayout_2->addWidget(txtConversation);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        horizontalLayout_2->addWidget(btnClear);

        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        horizontalLayout_2->addWidget(btnSend);


        verticalLayout_2->addLayout(horizontalLayout_2);

        txtMessage = new QPlainTextEdit(centralwidget);
        txtMessage->setObjectName(QStringLiteral("txtMessage"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtMessage->sizePolicy().hasHeightForWidth());
        txtMessage->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(txtMessage);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        verticalLayout_2->addLayout(horizontalLayout_7);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        lblCharCount = new QLabel(centralwidget);
        lblCharCount->setObjectName(QStringLiteral("lblCharCount"));

        verticalLayout_2->addWidget(lblCharCount);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BlackChat", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        comboDevSelect->clear();
        comboDevSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "-- Select USB Device --", 0)
        );
        btnDevRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0));
        btnDevConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        btnKeyGen->setText(QApplication::translate("MainWindow", "Generate Key", 0));
        txtDebug->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Droid Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Debugging Output</p></body></html>", 0));
        txtConversation->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Droid Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Conversation</p></body></html>", 0));
        btnClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        btnSend->setText(QApplication::translate("MainWindow", "Send", 0));
        txtMessage->setPlainText(QApplication::translate("MainWindow", "Message to Send", 0));
        label->setText(QApplication::translate("MainWindow", "Character Count:", 0));
        lblCharCount->setText(QApplication::translate("MainWindow", "1234", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
