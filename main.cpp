#include <iostream>
#include <allegro.h>

using namespace std;

#include "auto.h"
class Fondo{
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

}

int main()
{

   allegro_init();///inicia la libreria allegro

   install_keyboard();///comando para que podamos utilizar el teclado

   set_color_depth(32);/// establece la profundidad de color global de los píxeles.
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 600, 0, 0);///detecta el modo grafico de windows

  BITMAP*buffer= create_bitmap(SCREEN_W,SCREEN_H);///se crea una pantalla en la cual se imprimiran las imagenes

  Auto a;
Fondo f;
   while(!key[KEY_ESC])
   {
       clear_to_color(buffer,0xBC70B2);///limpa la pantalla

       f.dibujar(buffer);
       a.dibujar(buffer);
       a.mover();

       blit(buffer,screen,0,0,0,0,600,600);///imprime la pantalla en la cual se imprimiran las imagenes

   }



//a.dibujar(buffer);

return 0;
}
END_OF_MAIN(); /// para que allegro sepa donde termina el main
