#ifndef VERTICE_H
#define VERTICE_H

#include "Arista.h"
#include "vector"
#include "string"
#include "QLabel"
#include <QWidget>
#include <QPixmap>
#include <qpushbutton.h>
#include "jugador.h"
#include "iostream"
using namespace std;

class Vertice {
private:
    QLabel* identificadorLabel = nullptr;
    vector<Arista*> vecinos;
    string identificador;
public:
    QLabel* arbol = nullptr;
    Vertice(): identificador("") {}
    Vertice(string pIdentificador, Jugador* jugado): identificador(pIdentificador) {}

    int width = 120;
    int height = 120;
    int offset= 170;
    int ajuste= 145;
    void agregarArista(Vertice* vertice, int peso);

    void mostrarVecinos();

    void mostrar();

    string getIdentificador();

    vector<Arista*> getVecinos();

    QPoint crearQArbol(QWidget *parent, QPixmap& arbolImagen, int columna, int fila);

};

#endif // VERTICE_H
