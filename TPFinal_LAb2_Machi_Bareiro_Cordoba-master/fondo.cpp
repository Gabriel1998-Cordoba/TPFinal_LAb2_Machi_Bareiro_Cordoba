#include "fondo.h"

Fondo::Fondo()
{
    fondo=load_bitmap("imagenes/pista3.bmp",NULL);
    _x=0;
    _y=0;
}

void Fondo::dibujar(BITMAP* lienzo)
{
    draw_sprite(lienzo,fondo,_x,fondo->h*-1 + _y);
    draw_sprite(lienzo,fondo,_x,_y);
    //draw_sprite(lienzo,fondo,_x,fondo->h + _y);
    //draw_sprite(lienzo,fondo,_x,fondo->h*2 + _y);
    _y+=1;

    if(_y <= fondo->h*-1 || _y >= fondo->h)
    {
        _y = 0;
    }

}
Fondo:: ~Fondo()
{
    destroy_bitmap(fondo);
}
