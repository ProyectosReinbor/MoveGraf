#include "jugador.h"

void Jugador::moverA(const QPoint &p) {
    sprite->move(p.x(), p.y());
}
