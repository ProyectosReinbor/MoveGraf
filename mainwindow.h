#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "grafo.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_play_pressed();

    void on_crearGrafo_pressed();

private:
    Ui::MainWindow *ui;
    Grafo* grafoCargadoConTxt;
    Grafo* grafoParaCrearTxt;
};
#endif // MAINWINDOW_H
