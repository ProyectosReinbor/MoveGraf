/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_menu;
    QLabel *alerta;
    QLabel *fondo;
    QPushButton *play;
    QPushButton *crearGrafo;
    QWidget *page_juego;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        page_menu = new QWidget();
        page_menu->setObjectName("page_menu");
        alerta = new QLabel(page_menu);
        alerta->setObjectName("alerta");
        alerta->setGeometry(QRect(90, 60, 600, 300));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        alerta->setFont(font);
        alerta->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 44, 44);\n"
"padding:15px;\n"
"border-radius:15px;\n"
"font: 700 18pt \"Segoe UI\";"));
        alerta->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        fondo = new QLabel(page_menu);
        fondo->setObjectName("fondo");
        fondo->setGeometry(QRect(0, 0, 800, 600));
        fondo->setStyleSheet(QString::fromUtf8(""));
        fondo->setPixmap(QPixmap(QString::fromUtf8(":/assets/menu.jpg")));
        fondo->setScaledContents(true);
        play = new QPushButton(page_menu);
        play->setObjectName("play");
        play->setGeometry(QRect(200, 390, 400, 100));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setItalic(false);
        play->setFont(font1);
        play->setStyleSheet(QString::fromUtf8("font: bold;\n"
"background-color: rgb(13, 193, 202);\n"
"color:#000;\n"
"border-radius:20px;"));
        crearGrafo = new QPushButton(page_menu);
        crearGrafo->setObjectName("crearGrafo");
        crearGrafo->setGeometry(QRect(90, 260, 600, 100));
        crearGrafo->setFont(font1);
        crearGrafo->setStyleSheet(QString::fromUtf8("font: bold;\n"
"background-color: rgb(13, 193, 202);\n"
"color:#000;\n"
"border-radius:20px;"));
        stackedWidget->addWidget(page_menu);
        fondo->raise();
        play->raise();
        crearGrafo->raise();
        alerta->raise();
        page_juego = new QWidget();
        page_juego->setObjectName("page_juego");
        label_2 = new QLabel(page_juego);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 800, 600));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setSizeIncrement(QSize(1, 1));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/assets/background.jpg")));
        label_2->setScaledContents(true);
        stackedWidget->addWidget(page_juego);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        alerta->setText(QCoreApplication::translate("MainWindow", "hola wapos", nullptr));
        fondo->setText(QString());
        play->setText(QCoreApplication::translate("MainWindow", "PLAY", nullptr));
        crearGrafo->setText(QCoreApplication::translate("MainWindow", "CREAR GRAFO", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
