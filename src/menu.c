#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/structures.h"

int check_zone(Zone z, int x, int y) {
    return (x >= z.x && x <= (z.x + z.L) && y >= z.y && y <= (z.y + z.H));
}

int afficher_menu(int *choix, int *jeu2, int *exitgame) {
    Zone commencer = {758, 330, 179, 66};
    Zone obstacle = {747, 418, 179, 66};
    Zone exit = {750, 509, 179, 66};
    ChargerImageFond("image/menu.png");

    while (1) {
        SourisPosition();

        if (SourisCliquee()) {
            int x = _X;
            int y = _Y;

            if (check_zone(commencer, x, y)) {
                *choix = 1;
                return;
            } else if (check_zone(obstacle, x, y)) {
                *jeu2 = 1;
                return;
            } else if (check_zone(exit, x, y)) {
                *exitgame = 1;
                return;
            }
        }
    }
}
