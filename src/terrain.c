#include <stdlib.h>
#include <stdio.h>
#include <graph.h>  
#include "../include/structures.h"
#define TAILLE_INITIALE_SERPENT 10

void DessinerScene(TIMER *temps, TERRAIN *terrain, SERPENT *snake, PASTILLE *pill) {
    int i;
    char timerText[6];

    

    snprintf(timerText, 6, "%02d:%02d", temps->minute, temps->seconde);

    ChoisirCouleurDessin(CouleurParComposante(181, 236, 197));
    RemplirRectangle(20, 20, 1160, 700);

    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(10, 760, timerText, 2);

    snake->serpent = ChargerSprite("image/serpent.png");
    terrain->fond = ChargerSprite("image/fond.png");

    for (i = 0; i < TAILLE_INITIALE_SERPENT; i++) {
        AfficherSprite(snake->serpent, terrain->x - (i * 10), terrain->y);
        snake->pos_x[i] = terrain->x - (i * 10);
        snake->pos_y[i] = terrain->y;
        snake->old_x[i] = snake->pos_x[i];
        snake->old_y[i] = snake->pos_y[i];
    }

    srand(time(NULL));

    pill->pastille = ChargerSprite("image/pomme.png");
    for (pill->p = 0; pill->p < 5; pill->p++) {
        pill->pastillex[pill->p] = ((rand() % (57) + 1) * 20);
        pill->pastilley[pill->p] = ((rand() % (34) + 1) * 20);
        AfficherSprite(pill->pastille, pill->pastillex[pill->p], pill->pastilley[pill->p]);
        ChoisirCouleurDessin(CouleurParComposante(114, 148, 77));
        RemplirRectangle(0,0,20,800);
    }

if (terrain->obstacle_on == 1){  
        terrain->obstacle=ChargerSprite("image/mur.png");
        
        for (terrain->o = 0; terrain->o < 10; terrain->o++) {
            terrain->obstaclex[terrain->o] = ((rand() % (57)+1)*20);
            terrain->obstacley[terrain->o] = ((rand() % (34)+1)*20);
            AfficherSprite(terrain->obstacle, terrain->obstaclex[terrain->o],terrain->obstacley[terrain->o]);
        }
    }
}    