#include "auto.h"

Auto::Auto()
{
    _x=(SCREEN_W/2.2);
    _y=(SCREEN_H/1.2);
    ima_auto=load_bitmap("auto1bis.bmp",NULL);
    //setVida(3);
}
Auto::~Auto()
{
    destroy_bitmap(ima_auto);
}


void Auto::dibujar(BITMAP* buffer)
{
    draw_sprite(buffer,ima_auto,_x,_y);
}
void Auto:: mover()
{
//
//    if (key[KEY_UP] )
//        _y--;
//    if (key[KEY_DOWN] && _y<SCREEN_H-ima_auto->h )
//        _y++;
    if (key[KEY_LEFT] && _x>281)
        _x--;
    if (key[KEY_RIGHT] && _x<350)///SCREEN_W-ima_auto->w)
        _x++;
}
void Auto::destruir()
{
    destroy_bitmap(ima_auto);

}
