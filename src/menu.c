#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"

typedef struct {
    int x, y, L, H;
} Zone;

int check_zone(Zone z, int x, int y) {
    return (x >= z.x && x <= (z.x + z.L) && y >= z.y && y <= (z.y + z.H));
}

int afficher_menu(int *choix) {
    Zone boutonJouer = {741, 371, 184, 72};
    ChargerImageFond("image/menu.png");

    while (1) {
        SourisPosition();

        if (SourisCliquee()) {
            int x = _X;
            int y = _Y;

            if (check_zone(boutonJouer, x, y)) {
                *choix = 1;  
                break;
            }
        }
    }
}
