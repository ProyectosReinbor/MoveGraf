#include "Vertice.h"
#include "Arista.h"
#include "iostream"

void Vertice::agregarArista(Vertice* vertice, int peso) {

        vecinos.push_back(new Arista(vertice, peso));
    }

vector<Arista*> Vertice::getVecinos() {
    return vecinos;
}

void Vertice::mostrarVecinos() {
    for (int i = 0; i < vecinos.size(); i++) {
        cout << vecinos[i]->getVecino()->getIdentificador() << "(" << vecinos[i]->getPeso() << "), ";
    }
}

void Vertice::mostrar() {
    cout << identificador << " | ";
    mostrarVecinos();
    cout << endl;
}

string Vertice::getIdentificador() {
    return identificador;
}

QPoint Vertice::crearQArbol(QWidget *parent, QPixmap& arbolImagen, int columna, int fila) {
    if(arbol != nullptr || identificadorLabel != nullptr) {
        cout << "El vertice '" << identificador << "' ya tiene su QPanel creado." << endl;
        return QPoint(0,0);
    }

    arbol = new QLabel(parent);
    arbol->setFixedSize(width, height);
    arbol->setPixmap(arbolImagen.scaled(arbol->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int xVertice =  offset * columna - ajuste;
    int yVertice = offset * fila -  ajuste;
    arbol->move(xVertice, yVertice);
    arbol->show();

    QString Qidentificacion = QString::fromStdString(identificador);
    QLabel *nombreVertice = new QLabel(parent);
    nombreVertice->setText(Qidentificacion);
    nombreVertice->setStyleSheet(
        "color: rgb(255, 255, 255);"
        "background-color: rgb(44, 44, 44);"
        "padding:15px;"
        "border-radius:15px;"
        "font: 700 9pt 'Segoe UI'"
        );
    nombreVertice->move(xVertice - 5, yVertice - 5);
    nombreVertice->show();

    QPoint centroVertice(xVertice + (width/2), yVertice + (height/2));
    return centroVertice;
}
