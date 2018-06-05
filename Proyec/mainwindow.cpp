#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(0,0,700,400);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/fon1.jpg")));
    Bolas= new bola;

    scene->addItem(Bolas);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bola *MainWindow::get_carro()
{
    return Bolas;
}

