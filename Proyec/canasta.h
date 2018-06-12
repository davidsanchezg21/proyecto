#ifndef CANASTA_H
#define CANASTA_H

#include <QGraphicsItem>
#include <Qpainter>
class canasta: public QGraphicsItem
{
private:
    double px;
    double py;
public:
    canasta();
    canasta(double _px,double _py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void graficar();

    void setPx(double value);
    void setPy(double value);
};

#endif // CANASTA_H
