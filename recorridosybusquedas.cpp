// Recorrido en Anchura (BFS)
    void BFS(const string& inicio) {
        if (vertices.find(inicio) == vertices.end()) {
            cout << "Vertice no encontrado. "<<endl;
            return;
        }

        map<string, bool> visitado;
        queue<Vertice*> cola;
        Vertice* vInicio = vertices[inicio];

        visitado[vInicio->getNombre()] = true;
        cola.push(vInicio);

        cout << "\nRecorrido BFS desde " << inicio << ": ";

        while (!cola.empty()) {
            Vertice* actual = cola.front();
            cola.pop();
            cout << actual->getNombre() << " ";

            for (auto& vecino : actual->getAdyacentes()) {
                if (!visitado[vecino->getNombre()]) {
                    visitado[vecino->getNombre()] = true;
                    cola.push(vecino);
                }
            }
        }
        cout << endl;
    }

    // Recorrido en Profundidad (DFS)
    void DFS(const string& inicio) {
        if (vertices.find(inicio) == vertices.end()) {
            cout << "Vertice no encontrado. "<<endl;
            return;
        }

        map<string, bool> visitado;
        stack<Vertice*> pila;
        pila.push(vertices[inicio]);

        cout << " Recorrido DFS desde " << inicio << ": "<<endl;

        while (!pila.empty()) {
            Vertice* actual = pila.top();
            pila.pop();

            if (!visitado[actual->getNombre()]) {
                cout << actual->getNombre() << " ";
                visitado[actual->getNombre()] = true;

                  for (auto& it : actual->getAdyacentes()) {
                    if (!visitado[it->getNombre()]) {
                        pila.push(it);
                    }
                }
            }
        }
        cout << endl;
    }
    // Busqueda BFS ruta 
    void encontrarRutaBFS(const string& origen, const string& destino) {
        

        map<string, bool> visitado;
        map<string, string> predecesor;
        queue<string> cola;

        visitado[origen] = true;
        cola.push(origen);

        bool encontrado = false;

        while (!cola.empty() && !encontrado) {
            string actual = cola.front();
            cola.pop();

            for (auto vecino : vertices[actual]->getAdyacentes()) {
                string nombreVecino = vecino->getNombre();
                if (!visitado[nombreVecino]) {
                    visitado[nombreVecino] = true;
                    predecesor[nombreVecino] = actual;
                    cola.push(nombreVecino);

                    if (nombreVecino == destino) {
                        encontrado = true;
                        break;
                    }
                }
            }
        }

        if (!encontrado) {
            cout << "sin ruta " << origen << " a " << destino << endl;
            return;
        }

        vector<string> ruta;
        for (string v = destino; v != origen; v = predecesor[v]) {
            ruta.push_back(v);
        }
        ruta.push_back(origen);

        cout << " Ruta (BFS) de " << origen << " a " << destino << ": ";
        for (int i = ruta.size() - 1; i >= 0; --i) {
            cout << ruta[i] << " - " ;
           
        }
		 
       cout << " llega a destino " <<endl;
    }

    // ----------------------------------------------------
    // Busqueda DFS para encontrar ruta recursivo
    bool dfsRutaRec(const string& actual, const string& destino, map<string, bool>& visitado, vector<string>& ruta) {
        visitado[actual] = true;
        ruta.push_back(actual);

        if (actual == destino){ return true};

        for (auto vecino : vertices[actual]->getAdyacentes()) {
            if (!visitado[vecino->getNombre()]) {
                if (dfsRutaRec(vecino->getNombre(), destino, visitado, ruta))
                    return true;
            }
        }

        ruta.pop_back();
        return false;
    }

    void encontrarRutaDFS(const string& origen, const string& destino) {
        

        map<string, bool> visitado;
        vector<string> ruta;

        if (dfsRutaRec(origen, destino, visitado, ruta)) {
            cout << "Ruta (DFS) de  " << origen << " a " << destino << "- ";
            for (int i = 0; i < ruta.size(); i++) {
                cout << ruta[i] << " ";
                ;
            }
            cout << endl;
        } else {
            cout << "No existe";
        }
    }
};
 