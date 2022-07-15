#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

#include "personaje.h"
#include "alarma.h"
#include "allegro.h"
class Zombie : public Personaje{
private :
    BITMAP  *ima_choque;
    BITMAP * ima_zombie;
    Alarma alarma;

    public:
        Zombie();
        ~Zombie();
        void dibujar(BITMAP *);
        void mover(BITMAP *);
        void dibujarChoque(BITMAP *);
} ;

#endif // ZOMBIE_H_INCLUDED
