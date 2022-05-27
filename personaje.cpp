 #include "personaje.h"

   Personaje::Personaje()
{

}
void Personaje::dibujar(BITMAP *buffer)
{

}
void Personaje::mover(){}
  void Personaje::setX(int x)
    {
        _x=x;
    };
    void Personaje::setY(int y)
    {
        _y=y;
    };
    int Personaje::getX()
    {
        return _x;
    }
    int Personaje::getY()
    {
        return _y;
    }
