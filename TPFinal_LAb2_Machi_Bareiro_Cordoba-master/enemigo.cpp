#include "enemigo.h"


Enemigo::Enemigo()
{
    _x=281;
    _y=-100;
    ima_enemy=load_bitmap("imagenes/auto2.bmp",NULL);
    dx=340;
    dy=2;
}


void Enemigo::dibujar(BITMAP*buffer )
{
    draw_sprite(buffer,ima_enemy,_x,_y);

}

void Enemigo::mover(BITMAP*buffer)
{

    if(alarma.timer(10))///cada 10 milisegundos aumenta la posicion en "Y" del enemigo
    {
        //_x+=dx;
        _y+=dy;



    }
    if(_y >=600)  ///esta condicion determina hasta donde hace el movimiento de caida el enemigo
    {

        _y=0;      // if(_x==350)_x=281;

        switch(rand()%2)
        {
        case 0:
            _x=281;
            break;
        case 1:
            _x=dx;
            break;
        }
    }
}

Enemigo::~Enemigo()
{
    destroy_bitmap(ima_enemy);
}

