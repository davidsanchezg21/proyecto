#include "canasta.h"


canasta::canasta()
{
   px=0;
   py=0;
}

canasta::canasta(double _px, double _py)
{
    px=_px;
    py=_py;
}

QRectF canasta::boundingRect() const
{
    return QRectF(-35,-35,70,70);
}

void canasta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/cesta.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void canasta::graficar()
{
    setPos(px,py);
}

void canasta::setPx(double value)
{
    px = value;
}

void canasta::setPy(double value)
{
    py = value;
}
