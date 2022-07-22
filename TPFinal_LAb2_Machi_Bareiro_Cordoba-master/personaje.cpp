#include "personaje.h"

Personaje::Personaje()
{

}

void Personaje::setX(int x)
{
    _x=x;
};
void Personaje::setY(int y)
{
    _y=y;
};
//void Personaje::setVida(int vida)
//{
//    _vida=vida;
//};
int Personaje::getVida()
{
    return _vida;
};
int Personaje::getX()
{
    return _x;
}
int Personaje::getY()
{
    return _y;
}
