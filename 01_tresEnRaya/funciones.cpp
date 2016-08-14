#include "funciones.h"
#include <allegro5/allegro.h>

void meterDatos(struct Bloque cuadrado[9]){
    int X = -50, Y = 50;
    int i = 0;
    /*POSICIONAR Y METER IMÁGENES*/
    for(int fila = 0; fila < 3; fila ++){
        X += 150;
        for(int columna = 0; columna < 3; columna ++){
            Y += 150;
            cuadrado[i].x = X;
            cuadrado[i].y = Y;
            cuadrado[i].width = 150;
            cuadrado[i].height = 150;
            cuadrado[i].img = al_create_sub_bitmap(cuadradoVacio, 0, 0, 150, 150);
        }
    }
}
