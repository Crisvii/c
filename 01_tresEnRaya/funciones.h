#ifndef __FUNCIONES_H_

#define __FUNCIONES_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

struct Bloque{
    int x;
    int y;
    int width;
    int height;
    ALLEGRO_BITMAP *img = NULL;
};

extern void meterDatos(struct Bloque bloque[9]);

#endif
