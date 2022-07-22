#include <iostream>
#include <string>
#include <cstdio>
#include "puntaje.h"
#include "allegro.h"

using namespace std;
Puntaje::Puntaje()
{
    _puntos=0;
}

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

void Puntaje::setJugador(const char* jugador)
{
  strcpy(_jugador, jugador);
}


bool Puntaje::GuardarEnDisco() {
    FILE* p = fopen("puntajes.dat" , "ab");
    if (p == NULL) {
        return false;
    }
    bool guardo = fwrite(this, sizeof(Puntaje), 1, p);
    fclose(p);
    return guardo;
}

///bool Puntaje::GuardarEnDisco(int nroRegistro) {
///  FILE* p = fopen("puntajes.dat", "rb+");
///  if (p == NULL) {
///    return false;
///  }
///  fseek(p, nroRegistro * sizeof(Puntaje), SEEK_SET);
///  bool guardo = fwrite(this, sizeof(Puntaje), 1, p);
///  fclose(p);
///  return guardo;
///}

bool Puntaje::LeerDeDisco(int nroRegistro) {
  FILE* p = fopen("puntajes.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Puntaje), SEEK_SET);
  bool ok = fread(this, sizeof(Puntaje), 1, p);
  fclose(p);
  return ok;
}

int cantidad_puntajes(){
  FILE* p = fopen("puntajes.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  size_t bytes;
  int cant_reg;

  fseek(p, 0, SEEK_END);
  bytes = ftell(p);
  fclose(p);
  cant_reg = bytes / sizeof(Puntaje);
  return cant_reg;
}

int buscar_puntaje(int id) {
  Puntaje punt;
  int i = 0;
  int cant = cantidad_puntajes();
  for (i = 0; i < cant; i++) {
    punt.LeerDeDisco(i);
    if (punt.getPuntaje() == id) {
      return i;
    }
  }
  return -1;
}
//void IngresarNombre(BITMAP *lienzo)
//{
//
//    char nombre [4];
//    textout_centre_ex(lienzo,font,"INGRESE SU NOMBRE,SOLO 3 LETRAS",300,360,0xC0392B,0xF0F3F4);
//    cin.getline(nombre,4);
//
//}
//void Puntaje::dibujar(BITMAP* buffer)
//{
//    draw_sprite(buffer,ima_gameover,_x,_y)
//}
//

