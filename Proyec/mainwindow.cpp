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
    l1 = new QGraphicsLineItem(0,0,700,0);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/fon1.jpg")));
    Bolas= new bola;
    Bolas->posiciones(x,y);
    Bolas->movimiento();
    scene->addItem(Bolas);
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
    //canasta
    rect1 = scene->addRect(620,350,1,30);//rect dercha
    rect2= scene->addRect(550,350,1,30);//rect izq
    rect3= scene->addRect(550,340,70,1);//rect arriba
    rect4= scene->addRect(550,380,70,1);//rect abajo
    //obtaculos
    obst1 =scene->addRect(325,280,60,20);//izquier
    obst2 =scene->addRect(445,300,60,20);//derecha

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


    timer->start(20);
}


void MainWindow::mover()
{
  mov->MovimientoParabolico();
  Bolas->posiciones(mov->getPosx(),mov->getPosy());
  Bolas->movimiento();
}

void MainWindow::colision()
{
    if(Bolas->collidesWithItem(l1)){
      //movimientos.MovimientoParabolico();
    }
}
