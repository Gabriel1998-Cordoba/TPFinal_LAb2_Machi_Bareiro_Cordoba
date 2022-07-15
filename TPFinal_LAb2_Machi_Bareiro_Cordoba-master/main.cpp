#include <iostream>
#include <allegro.h>

using namespace std;


#include "auto.h"
#include "enemigo.h"
#include "zombie.h"
#include "fondo.h"
#include "Menu.h"
#include "gameover.h"
#include "puntaje.h"
#include <stdio.h>

int main()
{

       allegro_init();///inicia la libreria allegro

    install_keyboard();///comando para que podamos utilizar el teclado
    install_mouse();
    set_color_depth(32);/// establece la profundidad de color global de los píxeles.
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 600, 0, 0);///detecta el modo grafico de windows

    BITMAP*buffer= create_bitmap(SCREEN_W,SCREEN_H);///se crea una pantalla en la cual se imprimiran las imagenes
    BITMAP*fin=create_bitmap(600,600);///INICIALIZA CADA OBJETO

    Auto a;
    Enemigo e;
    Zombie z;
    Fondo f;
    Menu m;
    Puntaje punt;
    Alarma alarm;
    int puntaje = 0;
   punt.setPuntaje(puntaje);
///

    bool finDelJuego=false;


    while( !key[KEY_ESC] && !finDelJuego)
    {

        clear_to_color(buffer,0xBC70B2);///limpia la pantalla

        int op = m.draw(buffer);

        if(op==1)
        {
            int puntaje=0;
            int contadorVueltas=0;

            while(!key[KEY_ESC] && !finDelJuego)
            {

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
                     clear_to_color(buffer,0xBC70B2);///limpia la pantalla
                    destroy_bitmap(buffer);
                    Gameover go;
                    go.dibujar(fin);
                    textout_centre_ex(fin,font,"PUNTAJE",300,300,0xC0392B,0xF0F3F4);///
                    textprintf(fin,font,300,320,-1,"%d",punt.getPuntaje());///imprimen texto en la pantalla
                    punt.GuardarEnDisco();
                    blit(fin,screen,0,0,0,0,600,600);
                    rest(10);

                }
                if((z.getX()+50 >= a.getX() && z.getX()<=a.getX()+50) && (z.getY()+50>= a.getY() && z.getY()<= a.getY()+50))/// colicion de coordenadas
                {
                    z.dibujarChoque(buffer);
                    puntaje++;
                    punt.setPuntaje(puntaje);

                }
                textout_centre_ex(buffer,font,"PUNTAJE",120,300,0xFF0000,0x220303);///
                textprintf(buffer,font,120,320,-1,"%d",puntaje);///imprimen texto en la pantalla
            }
        }
        if(op==4) finDelJuego=true;

        blit(buffer,screen,0,0,0,0,600,600);///imprime la pantalla en la cual se imprimiran las imagenes
    }

    rest(5);///le da una pausa al programa
    destroy_bitmap(buffer);///cuando termina el programa destruye el buffer,se utiliza para liberar la memoria utilizada por el bitmap

//a.dibujar(buffer);
    return 0;

}
END_OF_MAIN(); /// para que allegro sepa donde termina el main
