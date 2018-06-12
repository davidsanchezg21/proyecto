#include "acceso.h"
#include "ui_acceso.h"
#include "mainwindow.h"

acceso::acceso(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::acceso)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,-500,1300,500);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/control.png")));
}

acceso::~acceso()
{
    delete ui;
}

void acceso::on_pushButton_clicked()
{

    MainWindow *mundo=new MainWindow();
    mundo->show();
    close();
}

void acceso::empezar()
{


}
