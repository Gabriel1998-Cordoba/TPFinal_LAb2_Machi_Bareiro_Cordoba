#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include <allegro.h>
class Personaje
{
protected:
    int _x;
    int _y;
    int _vida;
public:
    Personaje();
    void setX(int );
    void setY(int );
    //void setVida (int );
int getVida();
    int getX();
    int getY();

};



#endif // PERSONAJE_H_INCLUDED
