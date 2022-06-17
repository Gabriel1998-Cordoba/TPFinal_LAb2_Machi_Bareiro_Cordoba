#include <iostream>
#include <allegro.h>

using namespace std;


struct coord{
int x;
int y;
};


#include "auto.h"
#include "enemigo.h"
#include "fondo.h"

int main()
{

    allegro_init();///inicia la libreria allegro

    install_keyboard();///comando para que podamos utilizar el teclado

    set_color_depth(32);/// establece la profundidad de color global de los píxeles.
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 600, 0, 0);///detecta el modo grafico de windows

    BITMAP*buffer= create_bitmap(SCREEN_W,SCREEN_H);///se crea una pantalla en la cual se imprimiran las imagenes

    Auto a;
    Enemigo e;
    Fondo f;

    bool finDelJuego=false;

    while(!key[KEY_ESC]&& !finDelJuego)
    {

        clear_to_color(buffer,0xBC70B2);///limpia la pantalla

        f.dibujar(buffer);
        a.dibujar(buffer);
        a.mover();
        e.dibujar(buffer);
        e.mover(buffer);

        if((e.getX()+50 >= a.getX() && e.getX()<=a.getX()+50) && (e.getY()+50>= a.getY() && e.getY()<= a.getY()+50))///
        {
            finDelJuego=true;
        }
        blit(buffer,screen,0,0,0,0,600,600);///imprime la pantalla en la cual se imprimiran las imagenes
    }
//        rest(1);///le da una pausa al programa
destroy_bitmap(buffer);///cuando termina el programa destruye el buffer,se utiliza para liberar la memoria utilizada por el bitmap
//a.dibujar(buffer);
    return 0;
}
END_OF_MAIN(); /// para que allegro sepa donde termina el main
