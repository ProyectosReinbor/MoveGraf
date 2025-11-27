#include "Grafo.h"
#include "iostream"

    Vertice* Grafo::getVertice(string identificador) {
        return vertices[identificador];
    }

    map<string, Vertice*> Grafo::getVertices(){
        return vertices;
    }

    void Grafo::agregarVertice(string identificador) {
        if(vertices.find(identificador) != vertices.end()) {
            return; // ya existe
        }
        vertices[identificador] = new Vertice(identificador);
    }

    void Grafo::agregarArista(string origen, string destino, int peso) {
        agregarVertice(origen);
        agregarVertice(destino);

        vertices[origen]->agregarArista(vertices[destino], peso);
        vertices[destino]->agregarArista(vertices[origen], peso);
    }

    void Grafo::mostrar() {
        cout << "Grafo: " << endl;
        cout << "Identificador | Vecinos" << endl;
        for(auto& it : vertices) {
            it.second->mostrar();
        }
    }

    string Grafo::obtenerTxt() {
        string txt = "";
        // & para hacer referencia al mismo objeto en memoria, y no crear una copia igual
        // const varibale constante no se puede cambiar
        for(const auto& vertice:vertices) {
            const string& origen = vertice.first;
            for(auto& arista:vertice.second->getVecinos()) {
                const string& destino = arista->getVecino()->getIdentificador();
                string peso = to_string(arista->getPeso());
                txt += origen + " " + destino + " " + peso + "\n";
            }
        }
        return txt;
    }
