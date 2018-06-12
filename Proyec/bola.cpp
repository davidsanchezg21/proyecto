#include "bola.h"

bola::bola()
{
    posy =0;
    posx =0;
}

QRectF bola::boundingRect() const
{
    return QRectF(-15,-15,30,30);

}

void bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/bola.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void bola::posiciones(double _Px, double _Py)
{
   posx=_Px;
   posy=_Py;
}

void bola::movimiento()
{
    setPos(posx,-posy);
}

void bola::choque_bordes()
{
    MovimientoParabolico();
    if(posx-15<=0){
        posx=15;
        vx=-Ce*vx;
    }
    if(posx+15>=1300){
        posx=1300-15;
        vx=0;
    }
    if(posy-15<=0){
        posy=15;
        posx=15;
        vy=0;
    }
    if(posy+15>=500){
        posy=500-15;
        vy=-Ce*vy;
    }

    movimiento();
}

void bola::salto_ini(double vi, double x, double y, double ang)
{
    vx=vi*cos(ang);
    vy=vi*sin(ang);
    posx=x;
    posy=y;
    angulo=ang;
}

void bola::MovimientoParabolico()
{

    vy=vy+(-G)*Delta;
    posx=posx+vx*Delta;
    posy=posy+vy*Delta+(0.5*(-G)*Delta*Delta);
}
double bola::getVx_ini() const
{
    return vx;
}

float bola::getPx() const
{
    return posx;
}

void bola::setPx(double value)
{
    posx = value;
}

float bola::getPy() const
{
    return posy;
}

void bola::setPy(double value)
{
    posy = value;
}


void bola::setVy_ini(double value)
{
    vy = value;
}
void bola::setVx_ini(double value)
{
    vx = value;
}
