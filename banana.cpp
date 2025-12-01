#include "Banana.h"
bool Banana::yaCreada() const {
    return bananaLabel != nullptr;
}

Banana::Banana(QWidget* parent, QPixmap& bananaImg, int x, int y, string pVerticeIdentificador):width(60), height(60) {
    bananaLabel = new QLabel(parent);
    bananaLabel->setFixedSize(width, height);
    bananaLabel->setPixmap(bananaImg.scaled(
        bananaLabel->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        ));

    bananaLabel->move(x - width/2, y - height/2);
    bananaLabel->show();
    verticeIdentificador=pVerticeIdentificador;
}
