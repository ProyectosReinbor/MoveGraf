#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFile"
#include "lineasgrafo.h"
#include "map"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->alerta->hide();
    srand(time(nullptr));
    ui->stackedWidget->setCurrentWidget(ui->page_menu);
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

    QPixmap arbolImagen(":/assets/arbol.png");
    if (arbolImagen.isNull()) {
        ui->alerta->setText("imagen arbol no encontrada");
        ui->alerta->show();
        return;
    }

    QPixmap jugadorImagen(":/assets/jugador.png");
    if (jugadorImagen.isNull()) {
        ui->alerta->setText("imagen jugador no encontrada");
        ui->alerta->show();
        return;
    }

    QPixmap enemigoImagen(":/assets/enemigo.png");
    if (enemigoImagen.isNull()) {
        ui->alerta->setText("imagen enemigo no encontrada");
        ui->alerta->show();
        return;
    }

    QPixmap bananaImagen(":/assets/bananas.png");
    if (bananaImagen.isNull()) {
        ui->alerta->setText("imagen banana no encontrada");
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

    const map<string, Vertice*>& vertices = grafoCargadoConTxt->getVertices();
    int cantidadVertices = vertices.size();
    if (cantidadVertices == 0) {
        ui->alerta->setText("grafo vacío o no contiene vértices");
        ui->alerta->show();
        return;
    }
    int verticeBananasSpawn = rand() % cantidadVertices;
    int verticeSpawnJugador = 0;
    do {
       verticeSpawnJugador = rand() % cantidadVertices;
    }
    while(verticeSpawnJugador == verticeBananasSpawn);
    int verticeActualJugador = verticeSpawnJugador;
    int numEnemigos = 3;
    int indiceEnemigo = 0;
    int verticesSpawnEnemigos[3] = {0,0,0};
    for(int indiceEnemigo = 0; indiceEnemigo < numEnemigos; indiceEnemigo++) {
        do {
            verticesSpawnEnemigos[indiceEnemigo] = rand() % cantidadVertices;
        } while(verticesSpawnEnemigos[indiceEnemigo] == verticeBananasSpawn);
    }

    int indiceVertice = 0;
    int filas = 3;
    int columnas =5; // o calcula según cantidadVertices


    QLabel *vidaEnemigosLabels[3] = {nullptr,nullptr,nullptr};
    for(int i = 0; i < 3; i++) {
        vidaEnemigosLabels[i] = new QLabel(ui->page_juego);
        vidaEnemigosLabels[i]->setStyleSheet("background-color:#f00;");
        vidaEnemigosLabels[i]->move(80*i + 25, 500);
        vidaEnemigosLabels[i]->show();
    }

    for(auto & verticeMap : vertices) {
        int columna = indiceVertice / filas + 1;
        int fila    = indiceVertice % filas + 1;


        // crear Labels del vertice y guardar posicion
        Vertice* verticeIteracion = verticeMap.second;
        if(verticeIteracion == nullptr) {
            cout << "error vertice nullptr" << endl;
            continue;
        }
        QPoint posicionVertice = verticeIteracion->crearQArbol(ui->page_juego, arbolImagen, columna, fila);
        string verticeIdentificador = verticeIteracion->getIdentificador();
        grafoCargadoConTxt->posicionesVertices[verticeIdentificador] = posicionVertice;


        QPushButton *boton = new QPushButton("Click", ui->page_juego);
        boton->setGeometry(posicionVertice.x()-60, posicionVertice.y()-60, 120, 120);   // posición y tamaño
        boton->setStyleSheet("QPushButton { background-color: rgba(0, 0, 255, 30); }");
        boton->setProperty("id", QString::fromStdString(verticeIdentificador));
        connect(boton, &QPushButton::clicked, this, &MainWindow::verticePressed);

        if(indiceVertice == verticeBananasSpawn) {
            banana = new Banana(ui->page_juego, bananaImagen, posicionVertice.x(), posicionVertice.y(), verticeIdentificador);
        } else {
            if(indiceVertice == verticeSpawnJugador) {
                jugador = new Jugador(ui->page_juego, jugadorImagen, posicionVertice.x(), posicionVertice.y(), verticeIdentificador);
            }

            for(int i = 0; i < numEnemigos; i++){
                int verticeSpawnEnemigo = verticesSpawnEnemigos[i];
                if(verticeSpawnEnemigo == indiceVertice) {
                    enemigos[i] = new Enemigo(ui->page_juego, enemigoImagen, posicionVertice.x(), posicionVertice.y(), verticeIdentificador, vidaEnemigosLabels[i]);
                }
            }
        }

        indiceVertice++;
    }

    if(!banana) {
        cout << "error banana nullptr" << endl;
    }

    for(int i = 0; i < numEnemigos; i++){
        if(enemigos[i] == nullptr) {
            cout << "error enemigos no existe" << endl;
            return;
        }
        enemigos[i]->configurar(grafoCargadoConTxt, ui->stackedWidget, ui->pagePerdiste);
        enemigos[i]->moverCada4segundosPorRutaMasCorta(banana->verticeIdentificador);
    }


    LineasGrafo *lineas = new LineasGrafo(ui->page_juego);
    lineas->setGeometry(ui->page_juego->rect());
    lineas->raise(); // para que quede encima
    for (auto &p : vertices) {
        string origen = p.first;

        Vertice *v = p.second;
        for (auto &arista : v->getVecinos()) {
            string destino = arista->getVecino()->getIdentificador();
            string peso = to_string(arista->getPeso());
            QString idPosicion = QString::fromStdString(origen+destino+" "+peso);
            lineas->aristas[idPosicion] = qMakePair(grafoCargadoConTxt->posicionesVertices[origen], grafoCargadoConTxt->posicionesVertices[destino]);
        }
    }
    lineas->update();

    ui->alerta->hide();

    // agregar mapa a la ui con el while


    ui->stackedWidget->setCurrentWidget(ui->page_juego);

}

void MainWindow::verticePressed() {
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        if (!btn) return;

        QString id = btn->property("id").toString();
        qDebug() << "Presionó:" << id;
        Vertice* vertice = grafoCargadoConTxt->getVertice(id.toStdString());
        for(auto arista:vertice->getVecinos()){
            if(arista->getVecino()->getIdentificador()==jugador->verticeActualID ) {
                jugador->moverA(vertice->arbol->pos());
                jugador->verticeActualID =  id.toStdString();
                if(banana->verticeIdentificador == id.toStdString()) {
                    limpiarPageJuego();
                    ui->stackedWidget->setCurrentWidget(ui->pageGanaste);
                }
                break;
            }
        }
}


int RandomPeso() {
    return (rand() % 3) + 1;
}

void MainWindow::limpiarPageJuego() {
    // Elimina TODOS los hijos de page_juego
    QList<QObject*> hijos = ui->page_juego->children();
    for (QObject* obj : hijos) {
        QWidget* w = qobject_cast<QWidget*>(obj);
        if (w) {
            delete w;  // destruye el widget y lo remueve de la UI
        }
    }

    // Limpia punteros que usas
    banana = nullptr;
    jugador = nullptr;

    for (int i = 0; i < 3; i++) {
        enemigos[i] = nullptr;
    }
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


void MainWindow::on_pushButton_pressed()
{
    limpiarPageJuego();
    ui->stackedWidget->setCurrentWidget(ui->page_menu);
}


void MainWindow::on_pushButton_2_clicked()
{
    limpiarPageJuego();
    ui->stackedWidget->setCurrentWidget(ui->page_menu);
}


void MainWindow::on_pushButton_3_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->pageMatriz);

    grafoCargadoConTxt = new Grafo();
    QString ruta = QCoreApplication::applicationDirPath() + "/grafo.txt";
    QFile archivo(ruta);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->alerta->setText("archivo grafo no existe");
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

    const map<string, Vertice*>& vertices = grafoCargadoConTxt->getVertices();

    int filas = vertices.size();
    vector<string> verticesOrdenados;
    for(auto vertice:vertices) {
        string identi = vertice.second->getIdentificador();
        verticesOrdenados.push_back(identi);
    }
    int y = -1;
    int width = 40;
    int height = 40;
    int offset = 200;
    for(auto vertice:vertices) {
        Vertice* verticeY = vertice.second;
        string identi = verticeY->getIdentificador();
        cout << identi << endl;

        if(y == -1) {
            int x = -1;
            for(auto VerticeX:vertices) {
                string identiX = VerticeX.first;
                QLabel * label = new QLabel(ui->pageMatriz);
                label->move(width*x + offset, height*y + offset);
                label->setText(QString::fromStdString(identiX));
                label->show();
                x++;
            }
        }

            int x = -1;
            for(auto VerticeX:vertices) {
                string identiX = VerticeX.first;
                if(x == -1) {
                    QLabel * label = new QLabel(ui->pageMatriz);
                    label->move(width*x + offset, height*y + offset);
                    label->setText(QString::fromStdString(identi));
                    label->show();
                }
                    QLabel * label = new QLabel(ui->pageMatriz);
                    label->move(width*x + offset, height*y + offset);
                    string num = "0";
                    for(auto arista:verticeY->getVecinos()) {
                        if(arista->getVecino()->getIdentificador() == identiX) {
                            num = to_string(arista->getPeso());
                        }
                    }
                    label->setText(QString::fromStdString(num));
                    label->show();
                x++;
            }
        y++;
    }
}

