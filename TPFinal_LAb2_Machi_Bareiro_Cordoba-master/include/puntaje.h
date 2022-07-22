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
        Puntaje();
       void setPuntaje(int puntos);
        int getPuntaje();
        void setJugador(const char* jugador);
        string getJugador();
        bool GuardarEnDisco();
       /// bool GuardarEnDisco(int nroRegistro);
        bool LeerDeDisco(int nroRegistro);

       /// void dibujar(BITMAP* );
    private:
       int _puntos;
       char _jugador[50];
        BITMAP *ima_gameover;
};
///FuncionGlobal
int cantidad_puntajes();
///void IngresarNombre();
#endif // PUNTAJE_H
