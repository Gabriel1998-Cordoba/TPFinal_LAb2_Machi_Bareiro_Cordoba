#include "menu.h"

//#include <iostream>

// coordenadas de cada ítem del menú según la imagen
const Rect Menu:: Menu::items[] =
{
    { 515, 300, 745, 335 },             // Normal
    { 717, 375, 725, 410 },             // Rapido
    { 428, 455, 828, 490 },             // Estadisticas
    { 540, 535, 700, 570 }              // Salir
};

//// i es el índice del ítem (0..3)
bool Menu::sobreItem(int i)
{
    const Rect *r = &items[i];
    return mouse_x > r->x0 && mouse_x < r->x1 && mouse_y > r->y0 && mouse_y < r->y1;
}

Menu::Menu()
{
    fondoBase = load_bitmap("fondo0.bmp",NULL);
    fondos[0] = load_bitmap("fondo0.bmp",NULL);
    fondos[1] = load_bitmap("fondo1.bmp",NULL);
    fondos[2] = load_bitmap("fondo2.bmp",NULL);
    fondos[3] = load_bitmap("fondo3.bmp",NULL);
    cursor =load_bitmap("puntero.bmp",NULL);
//    over  = load_bitmap("imagenes/gameover.bmp",NULL);
//    imag_vida =load_bitmap("imagenes/vidac.bmp",NULL);

//    fnivel= load_bitmap("imagen/nivel.bmp",NULL);
//    explo2 = load_bitmap  ("imagen/explo2.bmp",NULL);
}

// la idea es que no sale del menú
// hasta que no elige una de las opciones
// retorna un entero de 0 a 3 según la opción elegida
int Menu::draw(BITMAP*lienzo)
{
    draw_sprite(lienzo,fondoBase,0,0);

     if(mouse_x > 440 && mouse_x < 745 && mouse_y > 288 && mouse_y < 333)
    {
        draw_sprite(lienzo,fondos[1],0,0);

        if(mouse_b & 1)
        {
            return 1;
        }
    }
//    int ret=-1;
//    int i;
//    while(ret < 0)
//    {
//
//            if(sobreItem(i))
//            {
//
//                draw_sprite(lienzo,fondos[i],0,0);
//
//                if(mouse_b & 1)
//                {
//
//                    ret = i;
//                }
//            }
//
  draw_sprite(lienzo,cursor,mouse_x,mouse_y);
//    }
//
//
//
//    return ret;
}

//void Menu::gameover(BITMAP*buffer) {
//    draw_sprite(buffer,over,0,0);
//}

// esta función no sé qué hace y no sé si va a ser necesaria
//void Menu::vidas(BITMAP*buffer, int op) {
//    switch(op) {
//    case 1:
//        masked_blit(imag_vida,buffer,0,0,35,10,40,31);
//        break;
//    case 2:
//        masked_blit(imag_vida,buffer,0,0,35,10,80,31);
//        break;
//    case 3:
//        draw_sprite(buffer,imag_vida,30,30);
//        break;
//    }
//}

//void Menu::nivel(BITMAP*buffer) {
//    draw_sprite(buffer,fnivel,0,0);
//}

//void Menu::explosion(BITMAP*buffer,int x,int y) { }
