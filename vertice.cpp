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
