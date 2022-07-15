
#include "zombie.h"


Zombie::Zombie()
{
    ima_zombie=load_bitmap("imagenes/zombie.bmp",NULL);
    _x=350;
    _y= -250;

}
Zombie::~Zombie()
{
destroy_bitmap(ima_zombie);
}


void Zombie::dibujar(BITMAP *lienzo)
{
      draw_sprite(lienzo,ima_zombie,_x,_y);


}

void Zombie::dibujarChoque(BITMAP *lienzo){
        ima_choque = load_bitmap("imagenes/zombiexplosion.bmp", NULL);
        _x=350;
        _y= -250;
        draw_sprite(lienzo,ima_choque,_x,_y);
}

void Zombie::mover(BITMAP*lienzo)
{

    if(alarma.timer(10))///cada 10 milisegundos aumenta la posicion en "Y" del enemigo
    {
        //_x+=dx;
        _y+=2;



    }
    if(_y >=800)  ///esta condicion determina hasta donde hace el movimiento de caida el enemigo
    {

        _y=-100;      // if(_x==350)_x=281;

        switch(rand()%2)
        {
        case 0:
            _x=281;
            break;
        case 1:
            _x=350;
            break;
        }
    }
}

