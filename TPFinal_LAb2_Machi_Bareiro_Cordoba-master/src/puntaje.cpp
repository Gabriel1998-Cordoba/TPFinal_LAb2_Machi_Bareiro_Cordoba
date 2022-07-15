#include <iostream>
#include <string>
#include <cstdio>
#include "puntaje.h"
#include "allegro.h"

using namespace std;

void Puntaje::setPuntaje(int puntos){
        _puntos = puntos;
}

int Puntaje::getPuntaje(){
        return _puntos;
}

string Puntaje::getJugador() {
    string jugador(_jugador);
    return jugador;
}

void Puntaje::setJugador(char jugador[50]) {
    _jugador[50] = jugador[50];
}

bool Puntaje::GuardarEnDisco() {
    FILE* p = fopen("puntaje.dat", "ab");
    if (p == NULL) {
        return false;
    }
    bool guardo = fwrite(this, sizeof(Puntaje), 1, p);
    fclose(p);
    return guardo;
}
//void Puntaje::dibujar(BITMAP* buffer)
//{
//    draw_sprite(buffer,ima_gameover,_x,_y)
//}
//
