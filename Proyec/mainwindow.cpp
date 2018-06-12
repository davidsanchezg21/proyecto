#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    x=15;
    y=15;
    timer = new QTimer;

    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,-500,1300,500);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/fon1.jpg")));

    Bolas= new bola;
    Bolas->posiciones(x,y);
    Bolas->movimiento();
    scene->addItem(Bolas);
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));

    obst.push_back(new obstaculos(900,20,60,100,0,5));
    obst.back()->mover();
    scene->addItem(obst.back());

    obst.push_back(new obstaculos(140,20,60,50,0,5));
    obst.back()->mover();
    scene->addItem(obst.back());

    cesta=new canasta(1265,-35);
    cesta->graficar();
    scene->addItem(cesta);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bola *MainWindow::get_carro()
{
    return Bolas;
}

void MainWindow::colisiones()
{
/*    for(int i = 0; i < obstaculos.size();i++){
        j=-1;
        float ce = 0.5;
        if(obstaculos.itera(i)->collidesWithItem(Bolas)){
            obstaculos.itera(i)->mover()->setveloc(-j*obstaculos.at(i)->mover()->getvx(),j*ce*obstaculo.at(i)->mov_esfera()->getvy());

}
    }
}
*/
}

void MainWindow::on_pushButton_clicked()
{

   // double x=Bolas->getPx();
   // double y=Bolas->getPy();

    double v=ui->vel->text().toDouble();
    double a=ui->ang->text().toDouble();
    double rad= (a/180)*3.1416;
    Bolas->salto_ini(v,x,y,rad);



    timer->start(20);
}


void MainWindow::mover()
{
   //iterador que recorre la lista
    for(list<obstaculos*>::iterator iterador=obst.begin(); iterador!=obst.end();++iterador){
      (*iterador)->mover();
      if((*iterador)->collidesWithItem(Bolas)){
    //          Bolas->setPx((*iterador)->getposx());
    //          Bolas->setPy((*iterador)->getPosy());

          Bolas->setPx(0);
          Bolas->setPy(0);
          Bolas->setVy_ini(0);
          Bolas->setVx_ini(0);
      }
    }
    if(Bolas->collidesWithItem(cesta)){
        Bolas->setPx(0);
        Bolas->setPy(0);
    }
    Bolas->choque_bordes();

}


