#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

#define G 9.8
#define Delta 0.1
#define Ce 1

class bola:public QObject,
        public QGraphicsPixmapItem
{
private:

    double v;
    double posx;
    double posy;
    double angulo;
    double vx;
    double vy;
   // /movimientos *moverbola;

public:
    bola();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void posiciones(double _Px, double _Py);
    void movimiento();
    void choque_bordes();
    void salto_ini(double vi, double x, double y, double ang);
    void MovimientoParabolico();

    //movimientos *mov_bola();
    float getPx() const;
    float getPy() const;
    double getVx_ini() const;
    double getVy_ini() const;


    void setPx(double value);
    void setPy(double value);
    void setVy_ini(double value);
    void setVx_ini(double value);
};

#endif // BOLA_H
