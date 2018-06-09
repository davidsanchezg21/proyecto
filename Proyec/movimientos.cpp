#include "movimientos.h"

movimientos::movimientos()
{
    

}


movimientos::movimientos(double vi, double x, double y, double ang)
{
     v_ini=vi;
     posx=x;
     posy=y;
     angulo=ang;
}
void movimientos::MovimientoParabolico()
{
    //qDebug()<<"posx= "<< posx <<"posy= "<< posy<<endl;
    vx_ini=v_ini*cos(angulo);
    vy_ini=v_ini*sin(angulo)-G*Delta;
    v_ini= (sqrt(pow(vx_ini,2)+(pow(vy_ini,2))));

    posx+=vx_ini*Delta;
    posy+=vy_ini*Delta-(0.5*G*Delta*Delta);
    angulo=atan2(vy_ini,vx_ini);

    // qDebug()<<"posx= "<< posx <<"posy= "<< posy<<endl;
}

void movimientos::movimientoBola()
{
   //setPos(X,Y);
}

double movimientos::getPosx() const
{
    return posx;
}

void movimientos::setPosx(double value)
{
    posx = value;
}

double movimientos::getPosy() const
{
    return posy;
}

void movimientos::setPosy(double value)
{
    posy = value;
}
