#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include <fstream>
#include <sstream>
#include <QDebug>
#include "qdebug.h"

#include "bola.h"
#include "obstaculos.h"
#include "canasta.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bola *get_carro();
    //int x(){return x};
    void setV(double value);
    void colisiones();

private slots:
    void on_pushButton_clicked();
    void mover();
    void on_verticalSlider_valueChanged(int value);

private:

    double x;
    double y;
    double v;
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    bola *Bolas;
    QTimer *timer;
    canasta *cesta;
    list <obstaculos*> obst;
};

#endif // MAINWINDOW_H
