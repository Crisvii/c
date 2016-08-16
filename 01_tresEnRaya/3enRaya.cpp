#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <strings.h>
#include "funciones.h"

#define SCREEN_X 500
#define SCREEN_Y 600
#define WIDTH 150
#define HEIGHT 150

int main(int argc, const char **argv){

    ALLEGRO_DISPLAY *ventana = NULL;
    ALLEGRO_BITMAP *cuadradoVacio = NULL;
    ALLEGRO_BITMAP *cuadrado_X = NULL;
    ALLEGRO_BITMAP *cuadrado_O = NULL;
    ALLEGRO_EVENT_QUEUE *evento = NULL;
    ALLEGRO_TIMER *reloj = NULL;
    bool doexit = false;
    struct Bloque cuadrado[9];

    al_init();
    al_init_image_addon();
    al_install_mouse();

    /*bloque[0] → vacio
     *  *      *bloque[1] → X
     *   *           *bloque[2] → O*/
    /*INICIAR ALLEGRO*/

    ventana = al_create_display(SCREEN_X, SCREEN_Y);
    evento = al_create_event_queue();
    reloj = al_create_timer(1.0/50);
    cuadradoVacio = create_sub_bitmap("imagenes/cuadradoVacio.png");
    cuadrado_X = al_load_bitmap("imagenes/cuadradoX.png");
    cuadrado_O = al_load_bitmap("imagenes/cuadradoO.png");

    al_register_event_source(evento, al_get_display_event_source(ventana));
    al_register_event_source(evento, al_get_mouse_event_source());
    al_register_event_source(evento, al_get_timer_event_source(reloj));
    al_start_timer(reloj);

    al_clear_to_color(al_map_rgb(62, 234, 157));
    al_flip_display();

    meterDatos(cuadrado);

    while(!doexit){
        ALLEGRO_EVENT ev;
        al_wait_for_event(evento, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            doexit = true;
    }

    //Destruir variables de allegro:
    al_destroy_display(ventana);
    al_destroy_timer(reloj);
    al_destroy_event_queue(evento);
    al_destroy_bitmap(cuadradoVacio);
    al_destroy_bitmap(cuadrado_X);
    al_destroy_bitmap(cuadrado_O);

    return EXIT_SUCCESS;
}
