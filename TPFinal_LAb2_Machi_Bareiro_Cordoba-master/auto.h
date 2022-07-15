#pragma once

#include<allegro.h>
#include "personaje.h"

class Auto : public Personaje
{
private:

    BITMAP* ima_auto;

public:
    Auto();
    ~Auto();
    void dibujar(BITMAP*);
    void mover();
    void destruir();
};


