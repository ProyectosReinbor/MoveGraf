#include "lineasgrafo.h"
#include <QPainter>
#include <iostream>

using namespace std;
LineasGrafo::LineasGrafo(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
}

void LineasGrafo::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::white, 3)); // grosor 3

    QVector<QColor> colores = { Qt::black, Qt::yellow, Qt::red };

    for (auto &params : aristas) {
        QStringList datos = params.first.split(' ', Qt::SkipEmptyParts);
        int peso = datos[1].toInt();
        // mostrar en consola
        painter.setPen(QPen(colores[peso-1], 3));
        painter.drawLine(params.second.first, params.second.second);
    }
}
