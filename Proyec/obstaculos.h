#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include <QGraphicsItem>
#include <QPainter>

#define delta 0.01


class obstaculos: public QGraphicsItem
{
    double posx;
    double posy;
    double vx;
    double vy;
    int r;
    int limite;
public:
    obstaculos();
    obstaculos(double _posx, double _posy,int _r, int limi,int _vx, int _vy);//constructor sobre cargado

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mover();
    void calVel();//calcula las velocidades
    double getposx();
     //variables get y set de la clase
    double getPosy();
    double setVelocidad(float _vx,float _vy);
};

#endif // OBSTACULOS_H
