#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H
#include "puntaje.h"
#include <allegro.h>


class Estadisticas
{

private:
    int _x;
    int _y;
    BITMAP*estadisticas;
public:
    Estadisticas();
~Estadisticas();
    void dibujar(BITMAP*);
    void Burbuja(int A[], int n);

};


#endif // ESTADISTICAS_H
