#include "enemigo.h"

Enemigo::Enemigo()
{
     _x=(SCREEN_W/2.2);
    _y=0;
    ima_enemy=load_bitmap("imagenes/auto2.bmp",NULL);
    dx=2;
    dy=2;
    cont =1;
}

void Enemigo::dibujar(BITMAP*buffer)
{
draw_sprite(buffer,ima_enemy,_x,_y);

}

void Enemigo::mover(BITMAP*buffer)
{

    if(alarma.timer(10))///cada 10 segundos aumenta la posicion en "Y" del enemigo
    {
        //_x+=dx;
        _y+=dy;



   } if(_y >=600)  ///esta condicion determina hasta donde hace el movimiento de caida el enemigo
        {
            _y=0;
//            cont=-1;
        }
}

Enemigo::~Enemigo()
{
    destroy_bitmap(ima_enemy);
}
