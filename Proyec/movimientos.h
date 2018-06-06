#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include "bola.h"
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include<QDebug>

#define G 9.8
#define Delta 0.1
class movimientos
{
public:
    movimientos();
    movimientos(double vi, double x, double y, double ang);
    void MovimientoParabolico();
    void movimientoBola();

    double getPosx() const;
    void setPosx(double value);

    double getPosy() const;
    void setPosy(double value);

private:

    double v_ini;
    double posx;
    double posy;
    double angulo;
    double vx_ini;
    double vy_ini;

};

#endif // MOVIMIENTOS_H
