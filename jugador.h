#ifndef JUGADOR_H
#define JUGADOR_H

#include <QPixmap>
#include <QLabel>
using namespace std;

class Jugador {
public:
    QLabel *sprite = nullptr;
    string verticeActualID = "";
    int width = 80, height = 80;
    Jugador(QWidget *parent, const QPixmap &imagen, int x, int y, string verticeActualI) {
        sprite = new QLabel(parent);
        sprite->setFixedSize(width, height);
        sprite->setPixmap(imagen.scaled(sprite->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        sprite->move(x + (width/2), y - (height/2));
        sprite->show();
        verticeActualID = verticeActualI;
    }

    void moverA(const QPoint &p);
};

#endif // JUGADOR_H
