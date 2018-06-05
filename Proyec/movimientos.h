#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include "bola.h"
#include <QGraphicsItem>
#include <QPainter>
class movimientos
{
public:
    movimientos();
    void MovimientoParabolico();
    void movimientoBola();

private:
    float X;
    float Y;
};

#endif // MOVIMIENTOS_H
