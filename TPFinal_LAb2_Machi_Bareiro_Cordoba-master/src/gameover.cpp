#include "gameover.h"

Gameover::Gameover()
{
    gameover=load_bitmap("imagenes/pista3.bmp", NULL);
    _x=0;
    _y=0;
}

void Gameover::dibujar(BITMAP* lienzo)
{
    draw_sprite(lienzo,gameover,_x,gameover->h*-1 + _y);
    draw_sprite(lienzo,gameover,_x,gameover->h*-2 + _y);
    draw_sprite(lienzo,gameover,_x,_y);
    draw_sprite(lienzo,gameover,_x,gameover->h + _y);
    draw_sprite(lienzo,gameover,_x,gameover->h*2 + _y);
    _y+=1;

    if(_y <= gameover->h*-1 || _y >= gameover->h)
    {
        _y = 0;
    }

}
///Gameover:: ~Gameover()
///{
///    destroy_bitmap(gameover);
///}

