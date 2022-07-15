#ifndef FONDO_H_INCLUDED
#define FONDO_H_INCLUDED

#include <allegro.h>

class Fondo
{
private:
    int _x;
    int _y;
    BITMAP*fondo;
public:
    Fondo();
~Fondo();
    void dibujar(BITMAP*);


};

#endif // FONDO_H_INCLUDED
