#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED

 #include "personaje.h"
#include "alarma.h"



 class Enemigo: public Personaje{
protected:
    //int vida;
    BITMAP* ima_enemy;
    int dx;
    int dy;
    Alarma alarma;
public:
    Enemigo();
    ~Enemigo();
   int getDX(){return dx;}
    void dibujar (BITMAP*);
    void mover (BITMAP*);

 };
#endif // ENEMIGO_H_INCLUDED
