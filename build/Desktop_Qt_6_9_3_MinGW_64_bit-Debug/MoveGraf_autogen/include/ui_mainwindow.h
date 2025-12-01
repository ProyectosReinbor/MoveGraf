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
    QWidget *pageMatriz;
    QLabel *label_6;
    QWidget *page_menu;
    QLabel *alerta;
    QLabel *fondo;
    QPushButton *play;
    QPushButton *crearGrafo;
    QPushButton *pushButton_3;
    QLabel *label_7;
    QWidget *pageGanaste;
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QWidget *page_juego;
    QLabel *label_2;
    QLabel *pesosColor;
    QLabel *pesoNegro;
    QLabel *pesoNegro_2;
    QLabel *pesoNegro_3;
    QWidget *pagePerdiste;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
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
        stackedWidget->setGeometry(QRect(0, -50, 800, 600));
        pageMatriz = new QWidget();
        pageMatriz->setObjectName("pageMatriz");
        label_6 = new QLabel(pageMatriz);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(330, 60, 63, 20));
        stackedWidget->addWidget(pageMatriz);
        page_menu = new QWidget();
        page_menu->setObjectName("page_menu");
        alerta = new QLabel(page_menu);
        alerta->setObjectName("alerta");
        alerta->setGeometry(QRect(90, 70, 600, 300));
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
        pushButton_3 = new QPushButton(page_menu);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 380, 181, 100));
        label_7 = new QLabel(page_menu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(190, 60, 491, 171));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(true);
        label_7->setFont(font2);
        stackedWidget->addWidget(page_menu);
        fondo->raise();
        play->raise();
        crearGrafo->raise();
        alerta->raise();
        pushButton_3->raise();
        label_7->raise();
        pageGanaste = new QWidget();
        pageGanaste->setObjectName("pageGanaste");
        label_5 = new QLabel(pageGanaste);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, -20, 801, 581));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/assets/ganaste.jpg")));
        label_4 = new QLabel(pageGanaste);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(510, 450, 301, 171));
        QFont font3;
        font3.setPointSize(30);
        label_4->setFont(font3);
        pushButton_2 = new QPushButton(pageGanaste);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 510, 261, 61));
        stackedWidget->addWidget(pageGanaste);
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
        pesosColor = new QLabel(page_juego);
        pesosColor->setObjectName("pesosColor");
        pesosColor->setGeometry(QRect(650, 440, 121, 151));
        pesosColor->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 174, 255);\n"
"color: rgb(0, 0, 0);\n"
"padding:15px;\n"
"border-radius:15px;\n"
""));
        pesoNegro = new QLabel(page_juego);
        pesoNegro->setObjectName("pesoNegro");
        pesoNegro->setGeometry(QRect(690, 500, 63, 16));
        pesoNegro->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pesoNegro_2 = new QLabel(page_juego);
        pesoNegro_2->setObjectName("pesoNegro_2");
        pesoNegro_2->setGeometry(QRect(690, 530, 63, 16));
        pesoNegro_2->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 255, 0);"));
        pesoNegro_3 = new QLabel(page_juego);
        pesoNegro_3->setObjectName("pesoNegro_3");
        pesoNegro_3->setGeometry(QRect(690, 560, 63, 16));
        pesoNegro_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        stackedWidget->addWidget(page_juego);
        pagePerdiste = new QWidget();
        pagePerdiste->setObjectName("pagePerdiste");
        label = new QLabel(pagePerdiste);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 200, 211, 131));
        QFont font4;
        font4.setPointSize(20);
        label->setFont(font4);
        label_3 = new QLabel(pagePerdiste);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 10, 801, 581));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/assets/perdiste.jpg")));
        pushButton = new QPushButton(pagePerdiste);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 420, 191, 91));
        stackedWidget->addWidget(pagePerdiste);
        label_3->raise();
        label->raise();
        pushButton->raise();
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
        label_6->setText(QCoreApplication::translate("MainWindow", "matriz", nullptr));
        alerta->setText(QCoreApplication::translate("MainWindow", "hola wapos", nullptr));
        fondo->setText(QString());
        play->setText(QCoreApplication::translate("MainWindow", "PLAY", nullptr));
        crearGrafo->setText(QCoreApplication::translate("MainWindow", "CREAR GRAFO", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "matriz adyacencia", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "DONKEY MOVE DRAFS", nullptr));
        label_5->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Ganaste", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Jugar otra vez", nullptr));
        label_2->setText(QString());
        pesosColor->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Pesos</span></p><p>1</p><p>2</p><p>3</p></body></html>", nullptr));
        pesoNegro->setText(QString());
        pesoNegro_2->setText(QString());
        pesoNegro_3->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Perdiste", nullptr));
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "jugar otra vez", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
