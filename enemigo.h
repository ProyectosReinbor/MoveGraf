#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QPixmap>
#include <QLabel>
#include <qstackedwidget.h>
#include "grafo.h"

class Enemigo {
public:
    QLabel *sprite = nullptr;
    int width = 80, height = 80;
    int vida = 9;
    QLabel * vidaLabel = nullptr;

    QTimer *timerMovimiento = nullptr;
    string verticeActualId = "";
    Grafo *grafo;
    bool enemigoGano = false;
    QStackedWidget *stackedWidget;
    QWidget * perdistePage;

    Enemigo(QWidget *parent, const QPixmap &imagen, int x, int y, string pVerticeActualId, QLabel* vidaLabe) {
        sprite = new QLabel(parent);
        sprite->setFixedSize(width, height);
        sprite->setPixmap(imagen.scaled(sprite->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        sprite->move(x, y - (height/2));
        sprite->show();
        verticeActualId = pVerticeActualId;
        vidaLabel = vidaLabe;
        quitarVida(0);
    }

    void configurar(Grafo* g, QStackedWidget *stacWidget, QWidget * perdistePag) {
        grafo = g;
        stackedWidget = stacWidget;
        perdistePage = perdistePag;
    }

    void moverCada4segundosPorRutaMasCorta(const std::string &objetivo);

    void moverA(const QPoint &p);

    void quitarVida(int peso) {
        if(vidaLabel == nullptr) {
            cout << "vidaLabel nullptr" << endl;
        }
        vida -= peso;
        vidaLabel->setFixedSize(vida*5, 25);
        string texto = to_string(vida);
        if(vida <= 0) {
            delete sprite;
            sprite = nullptr;
        }
        vidaLabel->setText(QString::fromStdString(texto));
    }

    void moverAVertice(string destinoIdentificador) {
        QPoint point = grafo->posicionesVertices[destinoIdentificador];
        moverA(point);
    }
};


#endif // ENEMIGO_H
