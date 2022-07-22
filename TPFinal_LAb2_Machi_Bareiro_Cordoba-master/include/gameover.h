#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED

#include <allegro.h>

class Gameover
{
private:
    int _x;
    int _y;
    BITMAP*gameover;
public:
    Gameover();
~Gameover();
    void dibujar(BITMAP*);


};

#endif // GAMEOVER_H_INCLUDED
