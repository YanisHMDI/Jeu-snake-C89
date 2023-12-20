#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "structures.h"
#define TAILLE_INITIALE_SERPENT 10


void DessinerScene(TIMER *temps, TERRAIN *terrain, SERPENT *snake, PASTILLE *pill){
    int i;
    snprintf(temps->timer,6,"%02d:%02d", temps->minute, temps->seconde);
    ChoisirCouleurDessin(CouleurParComposante(128, 255, 0));
    RemplirRectangle(20,20,1160,700);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255)); 
    EcrireTexte(10,760,temps->timer,2);
    snake->serpent = ChargerSprite("serpent.png");
    terrain->fond = ChargerSprite("fond.png");

    for (i = 0; i < TAILLE_INITIALE_SERPENT; i++){
        AfficherSprite(snake->serpent, terrain->x-(i*10), terrain->y);
        snake->pos_x[i]=terrain->x-(i*20);
        snake->pos_y[i]=terrain->y;
        snake->old_x[i]=snake->pos_x[i];
        snake->old_y[i]=snake->pos_y[i];
    }
    srand(time(NULL));
    pill->pastille=ChargerSprite("pomme.png");
    for (pill->p = 0; pill->p < 5; pill->p++) {
        pill->pastillex[pill->p] = ((rand() % (57)+1)*20);
        pill->pastilley[pill->p] = ((rand() % (34)+1)*20);
        AfficherSprite(pill->pastille, pill->pastillex[pill->p],pill->pastilley[pill->p]);
    }
    
}
