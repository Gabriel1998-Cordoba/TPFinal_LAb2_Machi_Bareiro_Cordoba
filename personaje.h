#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include <allegro.h>
class Personaje
{
protected:
    int _x;
    int _y;
    int vida;
public:
    Personaje();
    virtual void dibujar(BITMAP *);
    virtual void mover();
    void setX(int );
    void setY(int );
    int getX();
    int getY();

};



#endif // PERSONAJE_H_INCLUDED
