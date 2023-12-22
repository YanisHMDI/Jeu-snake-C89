#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../include/serpent.h"
#include "../include/pastilles.h"
#include "../include/terrain.h"
#include "../include/jeu.h"
#include "../include/structures.h"
#include "../include/menu.h"
#include "../include/timer.h"
#define CYCLE 10000L
int lancer_jeu() {
    JEU jeu;
    TERRAIN terrain;
    SERPENT snake;
    TIMER temps;
    PASTILLE pill;
    jeu.direction = 4;
    jeu.last_direction = 4;
    jeu.score = 0;
    jeu.touche = 0;
    jeu.jeu_en_cours = 1;
    terrain.x = 600;
    terrain.y = 400;
    terrain.fond;
    snake.pos_x[2400];
    snake.pos_y[2400];
    snake.old_x[2400];
    snake.old_y[2400];
    snake.serpent;
    snake.segment = 10;
    pill.p;
    pill.pastille;
    pill.pastillex[5];
    pill.pastilley[5];
    
    
   
    EffacerEcran(CouleurParComposante(0, 0, 0));
    temps.suivant = Microsecondes() + CYCLE;
    temps.old_seconde = (temps.suivant / 1000000) % 10;
    DessinerScene(&temps, &terrain, &snake, &pill);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0, 700, 1200, 800);
    RemplirRectangle(0, 0, 20, 20);
   
    while (jeu.jeu_en_cours) {
        Controle(&jeu);
        if (jeu.paused == 0) {
            Timer(&temps);
            Update_Timer(&temps);
            Serpent(&snake, &terrain, &jeu, &pill);
            Pastille(&pill);
            Update_Score(&jeu);
        }
    }
    
}
int main() {
    int choix = 0;

    InitialiserGraphique();
    CreerFenetre(350, 100, 1200, 800);
    afficher_menu(&choix);

    if (choix == 1) {
        lancer_jeu();
    } 
    
    if (choix == 2) {
        FermerGraphique();
        return EXIT_SUCCESS;
    } 

    FermerGraphique();
    return EXIT_SUCCESS;
}