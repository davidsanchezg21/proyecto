#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include "bola.h"
#include "movimientos.h"

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
private slots:
    void on_pushButton_clicked();
    void mover();
    void colision();
private:

    double x;
    double y;
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    bola *Bolas;
    QTimer *timer;
    movimientos *mov;
    QGraphicsLineItem *l1;
    QGraphicsRectItem* rect1;
    QGraphicsRectItem* rect2;
    QGraphicsRectItem* rect3;
    QGraphicsRectItem* rect4;
    QGraphicsRectItem* obst1;
    QGraphicsRectItem* obst2;



};

#endif // MAINWINDOW_H
