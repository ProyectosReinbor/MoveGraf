#ifndef ARISTA_H
#define ARISTA_H

class Vertice;

class Arista {
private:
    Vertice * vecino;
    int peso;
public:
    Arista():peso(1) {}
    Arista(Vertice* pVecino, int pPeso): vecino(pVecino), peso(pPeso) {}

    Vertice* getVecino();

    int getPeso();
};

#endif // ARISTA_H
