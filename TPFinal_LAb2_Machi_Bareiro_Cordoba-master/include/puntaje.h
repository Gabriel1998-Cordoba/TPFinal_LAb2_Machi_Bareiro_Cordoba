#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <iostream>
#include <string>
#include <cstdio>
#include "allegro.h"

using namespace std;


class Puntaje
{
    public:
       void setPuntaje(int puntos);
        int getPuntaje();
        void setJugador(char jugador[50]);
        string getJugador();
        bool GuardarEnDisco();
       // void dibujar(BITMAP* );
    private:
       int _puntos;
       char _jugador[50];
        BITMAP *ima_gameover;
};

#endif // PUNTAJE_H
