#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Grafo.h"
#include "QFile"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->alerta->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_pressed()
{
    grafoCargadoConTxt = new Grafo();
    QString ruta = QCoreApplication::applicationDirPath() + "/grafo.txt";
    QFile archivo(ruta);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->alerta->setText("archivo grafo no existe");
        ui->alerta->show();
        return;
    }

    QPixmap arbol(":/assets/arbol.jpg");
    if (arbol.isNull()) {
        ui->alerta->setText("imagen arbol no encontrada");
        ui->alerta->show();
        return;
    }

    QTextStream in(&archivo);
    while (!in.atEnd()) {

        QString line = in.readLine().trimmed(); // elimina espacios vacios del inicio y final de la linea
        if (line.isEmpty()) continue;

        QStringList partes = line.split(' ', Qt::SkipEmptyParts);
        if (partes.size() != 3) continue; // línea inválida

        QString origen  = partes[0];
        QString destino = partes[1];
        int peso = partes[2].toInt();

        grafoCargadoConTxt->agregarArista(origen.toStdString(), destino.toStdString(), peso);
    }


    int fila = 1;
    int columna = 1;
    int numeroFilas = 11;

    for(auto & verticeMap : grafoCargadoConTxt->getVertices()) {


        QLabel *vertice = new QLabel(ui->page_juego);
        vertice->setFixedSize(60, 60);
        vertice->setPixmap(arbol.scaled(vertice->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        vertice->move(70 * columna - 25, 70*fila - 25);
        vertice->show();

        QString identificacion = QString::fromStdString(verticeMap.first);
        QLabel *nombreVertice = new QLabel(ui->page_juego);
        nombreVertice->setText(identificacion);
        nombreVertice->setStyleSheet(
            "color: rgb(255, 255, 255);"
            "background-color: rgb(44, 44, 44);"
            "padding:15px;"
            "border-radius:15px;"
            "font: 700 9pt 'Segoe UI'"
            );
        nombreVertice->move(70 * columna - 25, 70*fila - 25);
        nombreVertice->show();

        fila++;
        if((fila % numeroFilas) == 0) {
            columna++;
            fila = 1;
        }
    }



    ui->alerta->hide();

    // agregar mapa a la ui con el while


    ui->stackedWidget->setCurrentWidget(ui->page_juego);
}


int RandomPeso() {
    return (rand() % 3) + 1;
}

void MainWindow::on_crearGrafo_pressed()
{
    QString ruta = QCoreApplication::applicationDirPath() + "/grafo.txt";
    QFile archivo(ruta);
    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->alerta->setText("archivo grafo no existe");
        ui->alerta->show();
        return;
    }
    ui->alerta->hide();
    grafoParaCrearTxt = new Grafo();
    map<string, vector<string>> aristasParametros = {};
    aristasParametros["A"] = {"B", "C", "D"};
    aristasParametros["B"] = {"A", "E", "F", "G"};
    aristasParametros["C"] = {"A", "G", "D"};
    aristasParametros["D"] = {"A", "C", "H"};
    aristasParametros["E"] = {"B"};
    aristasParametros["F"] = {"B", "I"};
    aristasParametros["G"] = {"C", "B", "J"};
    aristasParametros["H"] = {"D", "J"};
    aristasParametros["I"] = {"F", "J", "K"};
    aristasParametros["J"] = {"G", "I", "K"};
    aristasParametros["K"] = {"I", "J"};

    for(auto& parametros:aristasParametros) {
        string origen = parametros.first;
        for(string& destino:parametros.second) {
            grafoParaCrearTxt->agregarArista(origen, destino, RandomPeso());
        }
    }

    archivo.resize(0);
    QTextStream out(&archivo);
    out << QString::fromStdString(grafoParaCrearTxt->obtenerTxt());

    archivo.close();
}

