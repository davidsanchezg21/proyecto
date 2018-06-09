#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsItem>
#include <QPainter>
#include "movimientos.h"


class bola:public QObject,
        public QGraphicsPixmapItem
{
private:
    float Px;
    float Py;
   // /movimientos *moverbola;

public:
    bola();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void posiciones(float _Px, float _Py);
    void movimiento();

    //movimientos *mov_bola();
    float getPx() const;
    float getPy() const;

    void setPx(float value);
    void setPy(float value);
};

#endif // BOLA_H
