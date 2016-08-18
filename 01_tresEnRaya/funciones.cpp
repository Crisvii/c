#include "funciones.h"
#include <allegro5/allegro.h>

#define TAMANIO 150

void iniciar(struct Bloque cuadrado[9], ALLEGRO_BITMAP *sprites, int posicionX[9], int posicionY[9]){
    /*int X = -50, Y = 50;
    int i = 0;
    for(int fila = 0; fila < 3; fila ++){
        X += 150;
        for(int columna = 0; columna < 3; columna ++){
            Y += 150;
            cuadrado[i].x = X;
            cuadrado[i].y = Y;
            cuadrado[i].width = 150;
            cuadrado[i].height = 150;
            cuadrado[i].img = al_create_sub_bitmap(sprites, 0, 0, 150, 150);
        }
    }*/
    for(int i = 0; i < 9; i ++){
        cuadrado[i].x = posicionX[i];
        cuadrado[i].y = posicionY[i];
        cuadrado[i].width = TAMANIO;
        cuadrado[i].height = TAMANIO;
        cuadrado[i].img = al_create_sub_bitmap(sprites, 0, 0, 150, 150);
    }
}
