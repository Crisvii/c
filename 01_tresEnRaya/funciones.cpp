#include "funciones.h"
#include <allegro5/allegro.h>

#define TAMANIO 150

void iniciar(struct Bloque cuadrado[9], ALLEGRO_BITMAP *sprites, int posicionX[9], int posicionY[9]){

    for(int i = 0; i < 9; i ++){
        cuadrado[i].x = posicionX[i];
        cuadrado[i].y = posicionY[i];
        cuadrado[i].width = TAMANIO;
        cuadrado[i].height = TAMANIO;
        cuadrado[i].img = al_create_sub_bitmap(sprites, 0, 0, 170, 170);
    }
}
