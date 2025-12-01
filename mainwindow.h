#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "grafo.h"
#include <QMainWindow>
#include "banana.h"
#include "jugador.h"
#include "enemigo.h"


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

    void verticePressed();

    void on_play_pressed();

    void on_crearGrafo_pressed();

    void on_pushButton_pressed();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Grafo* grafoCargadoConTxt;
    Grafo* grafoParaCrearTxt;
    Banana* banana = nullptr;
    Jugador* jugador = nullptr;
    vector<Enemigo*> enemigos = {nullptr, nullptr, nullptr};
    void limpiarPageJuego();
};
#endif // MAINWINDOW_H
