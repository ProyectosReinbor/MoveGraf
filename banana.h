#ifndef BANANA_H
#define BANANA_H

#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QPoint>
#include "string"

using namespace std;

class Banana {
private:
    int width, height;

    QLabel* bananaLabel = nullptr;
public:
    string verticeIdentificador = "";
    Banana(QWidget* parent, QPixmap& bananaImg, int x, int y, string pVerticeIdentificador);
    bool yaCreada() const;
};

#endif // BANANA_H
