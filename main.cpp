#include <iostream>
#include <allegro.h>

using namespace std;


#include "auto.h"
#include "enemigo.h"
#include "zombie.h"
#include "fondo.h"
#include "Menu.h"

int main()
{

    allegro_init();///inicia la libreria allegro

    install_keyboard();///comando para que podamos utilizar el teclado
    install_mouse();
    set_color_depth(32);/// establece la profundidad de color global de los píxeles.
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 600, 0, 0);///detecta el modo grafico de windows

    BITMAP*buffer= create_bitmap(SCREEN_W,SCREEN_H);///se crea una pantalla en la cual se imprimiran las imagenes
///INICIALIZA CADA OBJETO

    Auto a;
    Enemigo e;
    Zombie z;
    Fondo f;
    Menu m;
///
    int puntaje=0;
    bool finDelJuego=false;

    while( !finDelJuego )
    {

        clear_to_color(buffer,0xBC70B2);///limpia la pantalla

        int op = m.draw(buffer);

        if(op==1)
        {

while(!key[KEY_ESC] && !finDelJuego){

                draw_sprite(screen,buffer,0,0);
                clear_to_color(buffer,0xBC70B2);///limpia la pantalla

                f.dibujar(buffer);
                a.dibujar(buffer);
                a.mover();
                z.dibujar(buffer);
                z.mover(buffer);
                e.dibujar(buffer);
                e.mover(buffer);

                if((e.getX()+50 >= a.getX() && e.getX()<=a.getX()+50) && (e.getY()+50>= a.getY() && e.getY()<= a.getY()+50))/// colicion de coordenadas
                {
                    finDelJuego=true;

                }
        }
                textout_centre_ex(buffer,font,"PUNTAJE",120,300,0xFF0000,0x220303);///
                textprintf(buffer,font,120,320,-1,"%d",puntaje);///imprimen texto en la pantalla


        }





        blit(buffer,screen,0,0,0,0,600,600);///imprime la pantalla en la cual se imprimiran las imagenes
    }

    rest(5);///le da una pausa al programa
    destroy_bitmap(buffer);///cuando termina el programa destruye el buffer,se utiliza para liberar la memoria utilizada por el bitmap

//a.dibujar(buffer);
    return 0;

}
END_OF_MAIN(); /// para que allegro sepa donde termina el main
