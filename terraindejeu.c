
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>

// Déclaration de la fonction d'initialisation du jeu
void initializeGame(, int *pastilleX, int *pastilleY, int terrain[40][60]);

int main() {
   int CreerFenetre(int posx,int posy,int L,int H);
    return 0;
}

// Définition de la fonction d'initialisation du jeu
void (, int *pastilleX, int *pastilleY, int terrain[40][60]) {
    // Initialisation du serpent au centre du terrain
    (snake, 30, 20);

    // Initialisation du terrain avec des cases vides
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 60; j++) {
            terrain[i][j] = 0;
        }
    }

    // Placement des pastilles sur le terrain
    for (int k = 0; k < 5; k++) {
        int x, y;
        do {
            // Génération de coordonnées aléatoires pour les pastilles
            x = rand() % 60;
            y = rand() % 40;
        } while (terrain[y][x] != 0);  // Vérification si la case est occupée

        // Marquer la case comme occupée par une pastille
        terrain[y][x] = 2;  // Utilisation de 2 pour représenter une pastille

        // Stocker les coordonnées de la première pastille pour l'exemple
        if (k == 0) {
            *pastilleX = x;
            *pastilleY = y;
        }
    }
}
