#include "Grafo.h"
#include "iostream"
#include <queue>
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
        vertices[identificador] = new Vertice(identificador, nullptr);
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

    vector<string> Grafo::dijkstra(string origen, string destino) {
        // Si no existen, devolver vacío
        if (vertices.find(origen) == vertices.end() ||
            vertices.find(destino) == vertices.end()) {
            return {};
        }

        // Distancias iniciales
        unordered_map<string, int> dist;
        unordered_map<string, string> previo;

        for (auto& par : vertices) {
            dist[par.first] = std::numeric_limits<int>::max();
        }

        dist[origen] = 0;

        // Min-heap: (distancia, identificador del vértice)
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
            > pq;

        pq.push({0, origen});

        while (!pq.empty()) {
            auto actual = pq.top();
            pq.pop();

            int distActual = actual.first;
            string nodo = actual.second;

            if (nodo == destino) break;
            if (distActual > dist[nodo]) continue;

            Vertice* v = vertices[nodo];

            for (Arista* arista : v->getVecinos()) {
                string vecino = arista->getVecino()->getIdentificador();
                int peso = arista->getPeso();

                int nuevaDist = distActual + peso;

                if (nuevaDist < dist[vecino]) {
                    dist[vecino] = nuevaDist;
                    previo[vecino] = nodo;
                    pq.push({nuevaDist, vecino});
                }
            }
        }

        // Si no hay camino7
        if (dist[destino] == std::numeric_limits<int>::max()) {
            return {};
        }

        // Reconstrucción del camino
        vector<string> camino;
        for (string v = destino; v != ""; v = previo.count(v) ? previo[v] : "") {
            camino.push_back(v);
            if (v == origen) break;
        }

        reverse(camino.begin(), camino.end());
        return camino;
    }
