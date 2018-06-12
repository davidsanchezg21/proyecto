#include "obstaculos.h"

obstaculos::obstaculos()
{
    posx=0;
    posy=0;
    vx=0;
    vy=0;
    r=0;
    limite=0;

}
obstaculos::obstaculos(double _posx, double _posy,int _r, int _limi,int _vx, int _vy)
{
    posx=_posx;
    posy=_posy;
    vx=_vx;
    vy=_vy;
    r=_r;
    limite=_limi;

}
QRectF obstaculos::boundingRect() const
{
    return QRectF(-r,-10,2*r,20);

}

void obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/barra.jpg");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}

void obstaculos::mover()
{
    if(vy!=0){
        calVel();
    }
    posx=posx;
    posy=posy+vy;
    setPos(posx,-posy);

}


void obstaculos::calVel()
{
    //modifica posiocion para que no salga de la escena y cambia el sentido de la velocidad
    if(posy-10<=limite){
        vy=5;
        posy=limite+r;
    }
    if(posy+10>=450){
        vy=-5;
        posy=450-r;
    }

}

double obstaculos::getposx()
{
    return posx;

}

double obstaculos::getPosy()
{
    return posy;

}


double obstaculos::setVelocidad(float _vx, float _vy)
{
    vx = _vx;
    vy = _vy;
}
