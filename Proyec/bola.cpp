#include "bola.h"


float bola::getPx() const
{
    return Px;
}

void bola::setPx(float value)
{
    Px = value;
}

float bola::getPy() const
{
    return Py;
}

void bola::setPy(float value)
{
    Py = value;
}

bola::bola()
{

}

QRectF bola::boundingRect() const
{
    return QRectF(25,370,30,30);

}

void bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/bola.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void bola::posiciones(float _Px, float _Py)
{
   Px=_Px;
   Py=_Py;
}

void bola::movimiento()
{
    setPos(Px,Py);
}

