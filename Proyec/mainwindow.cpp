#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

     x=25;
     y=-370;
    ui->setupUi(this);
    timer = new QTimer;
    scene=new QGraphicsScene(0,0,700,400);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/fon1.jpg")));
    Bolas= new bola;
    Bolas->posiciones(x,y);
    Bolas->movimiento();
    scene->addItem(Bolas);
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bola *MainWindow::get_carro()
{
    return Bolas;
}


void MainWindow::on_pushButton_clicked()
{

   // double x=Bolas->getPx();
   // double y=Bolas->getPy();

    double v=40;
    double a=45;
    double rad= (a/180)*3.1416;
    mov= new movimientos(v,x,y,rad);
    //scene->addItem(Bolas);

    timer->start(20);
}


void MainWindow::mover()
{
  mov->MovimientoParabolico();
  Bolas->posiciones(mov->getPosx(),mov->getPosy());
  Bolas->movimiento();
}
