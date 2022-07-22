#include <iostream>
#include <allegro.h>
#include "puntaje.h"
#include "estadisticas.h"
using namespace std;




#include <stdio.h>

Estadisticas::Estadisticas()
{
    estadisticas=load_bitmap("imagenes/pista3.bmp",NULL);
    _x=0;
    _y=0;
}

void Estadisticas::dibujar(BITMAP* lienzo)
{
    Puntaje punt;
    Estadisticas est;
    draw_sprite(lienzo,estadisticas,_x,_y);
      textout_centre_ex(lienzo,font,"PUNTAJES",300,200,0xC0392B,0xF0F3F4);///
      int reg = cantidad_puntajes();
        int *A = new int [reg];
        for (int t = 0; t<reg; t++){ ///PONE EN 0 EL VECTOR A.
            A[t] = 0;
    }
        for (int l=0; l<reg; l++){
                if (punt.LeerDeDisco(l))
            A[l] = punt.getPuntaje();
        }

        est.Burbuja(A, reg);
      for (int i=0; i<reg; i++){
            if (A[i] ==0){

            }else{
                textprintf(lienzo,font,300,320+i*10,-1,"%d",A[i]);///imprimen texto en la pantalla
            }

            }
                delete (A);//}
      }

void Estadisticas::Burbuja(int A[], int n) {
	int aux, aux2, i, j = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n +1; j++) {
			if (A[i] < A[j]) {
				aux = A[i];

				A[i] = A[j];

				A[j] = aux;

			}
		}
	}
}

Estadisticas:: ~Estadisticas()
{
    destroy_bitmap(estadisticas);
}

