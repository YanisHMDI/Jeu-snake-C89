#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
<<<<<<< HEAD
#include "structures.h"
#include "terrain.h"
=======
#include "structure.h"
#include "terrain.h";
>>>>>>> refs/remotes/origin/master

#define TAILLE_INITIALE_SERPENT 10


<<<<<<< HEAD
void DessinerScene(TIMER temps, TERRAIN terrain, SERPENT snake){
    temps.seconde = 0; 
    temps.minute= 0 ;
    temps.timer[6];
    
=======
void DessinerScene_v2(TIMER temps, TERRAIN terrain, SERPENT snake){
    temps.seconde = 0; 
    temps.minute= 0 ;
    temps.timer[6];
    //int serpent;
>>>>>>> refs/remotes/origin/master
    
    int x = 600;
    int y = 400;
    int i = 0;
    int p = 0;

    int fond;

    terrain.pos_x[60];
    terrain.pos_y[60];
    terrain.old_x[60];
    terrain.old_y[60];

    int pastille, pastillex[5], pastilley[5];

    snprintf(temps.timer,6,"%02d:%02d", temps.minute, temps.seconde);
    ChoisirCouleurDessin(CouleurParComposante(128, 255, 0));
    RemplirRectangle(20,20,1160,700);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255)); 
    EcrireTexte(10,760,temps.timer,2);
    snake.serpent = ChargerSprite("serpent.png");
    fond = ChargerSprite("fond.png");

    for (i = 0; i < TAILLE_INITIALE_SERPENT; i++){
        AfficherSprite(snake.serpent, x-(i*10), y);
        terrain.pos_x[i] = x-(i*20);
        terrain.pos_y[i] = y;
        terrain.old_x[i] = terrain.pos_x[i];
        terrain.old_y[i] = terrain.pos_y[i];
    }
    srand(time(NULL));
    pastille=ChargerSprite("pomme.png");
    for (p = 0; p < 5; p++) {
        pastillex[p] = ((rand() % (58)+2)*20);
        pastilley[p] = ((rand() % (35)+2)*20);
        AfficherSprite(pastille, pastillex[p],pastilley[p]);
    }
    
}