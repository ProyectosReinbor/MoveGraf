#ifndef GRAFO_H
#define GRAFO_H

#include <map>
#include "Vertice.h"

class Grafo {
private:
    bool peso;
    map<string, Vertice*> vertices;
    bool direccion;
public:
    map<string, QPoint> posicionesVertices;
    Vertice* getVertice(string identificador);
    map<string, Vertice*> getVertices();

    void agregarVertice(string identificador);

    void agregarArista(string origen, string destino, int peso);

    void mostrar();

    string obtenerTxt();

    vector<string> dijkstra(string origen, string destino);
};

#endif // GRAFO_H
