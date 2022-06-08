#include <iostream>
#include <allegro.h>

using namespace std;

#include "auto.h"
#include "enemigo.h"
/*class Fondo{
private:
    int x;
    int y;
    BITMAP*fondo;
    public:
Fondo();
        void dibujar(BITMAP*);

};
Fondo::Fondo(){
    fondo=load_bitmap("imagenes/pista2.bmp",NULL);
    x=0;
    y=0;
    }

void Fondo::dibujar(BITMAP* lienzo)
{
          draw_sprite(lienzo,fondo,x,fondo->h*-1 + y);
		draw_sprite(lienzo,fondo,x,fondo->h*-2 + y);
		draw_sprite(lienzo,fondo,x,y);
		draw_sprite(lienzo,fondo,x,fondo->h + y);
		draw_sprite(lienzo,fondo,x,fondo->h*2 + y);
		y+=0.1;

		if(y <= fondo->h*-1 or y >= fondo->h)
		{	y = 0;	}

}*/

int main()
{

    allegro_init();///inicia la libreria allegro

    install_keyboard();///comando para que podamos utilizar el teclado

    set_color_depth(32);/// establece la profundidad de color global de los píxeles.
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 600, 0, 0);///detecta el modo grafico de windows

    BITMAP*buffer= create_bitmap(SCREEN_W,SCREEN_H);///se crea una pantalla en la cual se imprimiran las imagenes

    Auto a;
    Enemigo e;
//Fondo f;
    while(!key[KEY_ESC])
    {
        clear_to_color(buffer,0xBC70B2);///limpa la pantalla

        a.dibujar(buffer);
        a.mover();

        e.dibujar(buffer);
        e.mover(buffer);

if(e.getX()+50 >= a.getX() && e.getX()<=a.getX()+40 && e.getY()+45>= a.getY() && e.getY()<= a.getY()+50)///
{


 clear_to_color(buffer,0x000000);
 draw_sprite(screen,buffer,0,0);


}
        blit(buffer,screen,0,0,0,0,600,600);///imprime la pantalla en la cual se imprimiran las imagenes
//        rest(1);///le da una pausa al programa

    }

    destroy_bitmap(buffer);///cuando termina el programa destruye el buffer,se utiliza para liberar la memoria utilizada por el bitmap

//a.dibujar(buffer);

    return 0;
}
END_OF_MAIN(); /// para que allegro sepa donde termina el main
