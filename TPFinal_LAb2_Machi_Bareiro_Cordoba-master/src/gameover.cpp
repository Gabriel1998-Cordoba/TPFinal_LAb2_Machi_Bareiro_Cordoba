#include "gameover.h"

Gameover::Gameover()
{
    gameover=load_bitmap("imagenes/gameover.bmp", NULL);
    _x=0;
    _y=0;
}

void Gameover::dibujar(BITMAP* lienzo)
{
    draw_sprite(lienzo,gameover,_x,_y);
}
Gameover:: ~Gameover()
{
   destroy_bitmap(gameover);
}

