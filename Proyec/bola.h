#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsItem>
#include <QPainter>


class bola:public QObject,
        public QGraphicsPixmapItem
{
private:
    float Px;
    float Py;
public:
    bola();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void posiciones(float _Px, float _Py);
    void movimiento();
    bola *get_carro();

    float getPx() const;
    float getPy() const;

    void setPx(float value);
    void setPy(float value);
};

#endif // BOLA_H
