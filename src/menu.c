#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/structures.h"

int check_zone(Zone z, int x, int y) {
    return (x >= z.x && x <= (z.x + z.L) && y >= z.y && y <= (z.y + z.H));
}

int afficher_menu(int *choix) {
    Zone commencer = {728,332,179,66};
    Zone exit = {728,448,179,66};
    ChargerImageFond("image/menu.png");

    while (1) {
        SourisPosition();

        if (SourisCliquee()) {
            int x = _X;
            int y = _Y;

            if (check_zone(commencer, x, y)) {
                *choix = 1;  
                return;
            }
        }
        if (SourisCliquee()) {
            int x = _X;
            int y = _Y;

            if (check_zone(exit, x, y)) {
                *choix = 2;  
                return;
            }
        }
    }
}
