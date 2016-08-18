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
    ALLEGRO_BITMAP *sprites = NULL;
    ALLEGRO_EVENT_QUEUE *evento = NULL;
    ALLEGRO_TIMER *reloj = NULL;
    bool doexit = false;
    struct Bloque cuadrado[9];
    /*Variables para guardar la posición de cada bloque del tablero tanto X como Y*/
    int posicionX[9];
    int posicionY[9];
    int inicialX = 25;
    int inicialY = 125;
    int aux = 0;

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
    sprites = al_load_bitmap("imagenes/sprites.png");

    al_register_event_source(evento, al_get_display_event_source(ventana));
    al_register_event_source(evento, al_get_mouse_event_source());
    al_register_event_source(evento, al_get_timer_event_source(reloj));
    al_start_timer(reloj);

    al_clear_to_color(al_map_rgb(62, 234, 157));
    al_flip_display();

    /*Introducir datos en las posiciones*/
    inicialY -= 150;
    for(int fila = 1; fila < 4; fila ++){
        inicialX = 25;
        inicialY += 150;
        for(int columna = 1; columna < 4;  columna ++){
            inicialX += 150;
            posicionX[aux] = inicialX;
            posicionY[aux] = inicialY;
            aux ++;
        }
    }

    iniciar(cuadrado, sprites, posicionX, posicionY);

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
    al_destroy_bitmap(sprites);

    return EXIT_SUCCESS;
}
