#include "enemigo.h"
#include <QTimer>
#include "iostream"
using namespace std;

void Enemigo::moverA(const QPoint &p) {
    cout << "hola wapos esto no se moverA" << endl;
    sprite->move(p.x(), p.y());
}



void Enemigo::moverCada4segundosPorRutaMasCorta(const string &objetivo) {
    if (grafo == nullptr) return;

    timerMovimiento = new QTimer(sprite);
    timerMovimiento->setInterval(4000); // 4 segundos

    QObject::connect(timerMovimiento, &QTimer::timeout, [=]() {
        if(enemigoGano == true) return;
        vector<string> camino = grafo->dijkstra(this->verticeActualId, objetivo);
        if (camino.size() < 2) return;

        string siguiente = camino[1];

        if(siguiente== objetivo) {
            cout << "enemigo gano" << endl;
            enemigoGano = true;
            this->stackedWidget->setCurrentWidget(perdistePage);
        }
        for(auto arista:this->grafo->getVertice(this->verticeActualId)->getVecinos()) {
            if(arista->getVecino()->getIdentificador() == siguiente) {
                cout << "quitar vida" << endl;
                this->quitarVida(arista->getPeso());
                break;
            }
        }
        this->verticeActualId = siguiente;
        this->moverAVertice(siguiente);
    });

    timerMovimiento->start();
}
