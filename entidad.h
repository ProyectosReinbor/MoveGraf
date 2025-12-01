#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <QLabel>
class Entidad
{
protected:
    QLabel *sprite = nullptr;
    int verticeActual = -1;
    int width = 80, height = 80;
public:

    Entidad() {}
    Entidad(QWidget *parent) {
        sprite = new QLabel(parent);
    }

    virtual ~Entidad() {}
};

#endif // ENTIDAD_H
