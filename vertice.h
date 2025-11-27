#ifndef VERTICE_H
#define VERTICE_H

#include "Arista.h"
#include "vector"
#include "string"

using namespace std;

class Vertice {
private:
    vector<Arista*> vecinos;
    string identificador;
public:
    Vertice(): identificador("") {}
    Vertice(string pIdentificador): identificador(pIdentificador) {}

    void agregarArista(Vertice* vertice, int peso);

    void mostrarVecinos();

    void mostrar();

    string getIdentificador();

    vector<Arista*> getVecinos();
};

#endif // VERTICE_H
