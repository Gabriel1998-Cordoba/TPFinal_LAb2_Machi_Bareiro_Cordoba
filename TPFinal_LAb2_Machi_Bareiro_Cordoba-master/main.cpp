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
#include "estadisticas.h"
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
    Estadisticas est;

    char nombre[50] = {};



    bool finDelJuego=false;

    clear_to_color(buffer,0xBC70B2);///limpia la pantalla

    while(!finDelJuego)//Comienza lla parte del menu
    {

        int op = m.draw(buffer); ///Se crea una variable "op" para recibir la opcion del menú

        if (op==3)
        {
            clear_to_color(buffer,0xBC70B2);///limpia la pantalla

            while(!key[KEY_ESC]){
                est.dibujar(buffer);
                blit(buffer, screen, 0,0,0,0,600,600);
            }

        }

        if(op==1)
        {
            Auto a;
            Enemigo e;
            Zombie z;
            Fondo f;
            Menu m;
//    Puntaje punt;
            Alarma alarm;
//    Estadisticas est;

            bool gameover=false;
            int puntaje = 0;//Se crean los objetos
            punt.setPuntaje(puntaje);


            while(!key[KEY_ESC]&& !gameover)
            {
                draw_sprite(screen,buffer,0,0);
                clear_to_color(buffer,0x000000);

//                textout_centre_ex(buffer,font,"PUNTAJE",120,300,0xFF0000,0x220303);///
//                textprintf(buffer,font,120,320,-1,"%d",punt.getPuntaje());///imprimen texto en la pantalla

                f.dibujar(buffer);
                a.dibujar(buffer);
                a.mover();
                z.dibujar(buffer);
                z.mover(buffer);
                e.dibujar(buffer);

                e.mover(buffer);
// Gameover go;



                if((e.getX()+50 >= a.getX() && e.getX()<=a.getX()+50) && (e.getY()+50>= a.getY() && e.getY()<= a.getY()+50))/// colicion de coordenadas
                {




//                    finDelJuego=true;
                    while(!key[KEY_SPACE])///bucle del gameover
                    {
                        draw_sprite(screen,fin,0,0);
                        clear_to_color(fin,0x000000);
                        Gameover go;
                        go.dibujar(fin);//Dibuja Fondo del GameOver
                        textout_centre_ex(fin,font,"PUNTAJE",300,300,0xC0392B,0xF0F3F4);///
                        textprintf(fin,font,300,320,-1,"%d",punt.getPuntaje());///imprimen texto en la pantalla

                        gameover=true;
                        blit(fin,screen,0,0,0,0,600,600);
//
//                        rest(10);
                    }
                }

                if((z.getX()+50 >= a.getX() && z.getX()<=a.getX()+50) && (z.getY()+50>= a.getY() && z.getY()<= a.getY()+50))/// colicion de coordenadas
                {
                    z.dibujarChoque(buffer);
                    puntaje++;
                    punt.setPuntaje(puntaje);

                }
                textout_centre_ex(buffer,font,"PUNTAJE",120,300,0xFF0000,0x220303);///
                textprintf(buffer,font,120,320,-1,"%d",punt.getPuntaje());///imprimen texto en la pantalla
            }
            if(punt.GuardarEnDisco())
            {
                textout_centre_ex(fin,font,"Se Pudo Guardar",300,300,0xC0392B,0xF0F3F4);///
            }
            else
            {
                textout_centre_ex(fin,font,"No se pudo guardar",300,300,0xC0392B,0xF0F3F4);///

            }
        }
        if(op==4) finDelJuego=true;

        blit(buffer,screen,0,0,0,0,600,600);///imprime la pantalla en la cual se imprimiran las imagenes
    }

    rest(5);///le da una pausa al programa
    destroy_bitmap(buffer);///cuando termina el programa destruye el buffer,se utiliza para liberar la memoria utilizada por el bitmap


    return 0;

}
END_OF_MAIN(); /// para que allegro sepa donde termina el main
