
#pragma once
#include <allegro.h>
// estructura de coordenadas de un rectángulo (izq, sup, der, inf)
typedef struct {
    int x0, y0, x1, y1;
} Rect;

class Menu {
private:
    BITMAP* fondoBase;      // fondo del menú sin destacar un ítem
    BITMAP* fondos[4];      // arreglo de 4 imágenes para los ítems
//BITMAP* fondo0;
    BITMAP* cursor;
//    BITMAP* over;
//    BITMAP* imag_vida;
//    BITMAP* fnivel;
//    BITMAP* explo2;

    static const Rect items[4]; // coordenadas de cada ítem del menú

    bool sobreItem(int i);      // función que detecta si el mouse está sobre uno de los ítems

public:
    Menu();
int draw(BITMAP*);

    void gameover(BITMAP*);
//    void vidas(BITMAP*,int);
//    void nivel(BITMAP*);
//    void explosion(BITMAP*,int,int);
};
