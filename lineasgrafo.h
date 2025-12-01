#ifndef LINEASGRAFO_H
#define LINEASGRAFO_H
#include <QWidget>
#include <map>
#include <QPoint>

using namespace std;

class LineasGrafo : public QWidget {
    Q_OBJECT
public:
    explicit LineasGrafo(QWidget *parent = nullptr);
    map<QString, QPair<QPoint, QPoint>> aristas;

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // LINEASGRAFO_H
