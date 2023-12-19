#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "serpent.h"
#include "pastilles.h"
#include "terrain.h"
#include "jeu.h"
#include "structures.h"
#define CYCLE 10000L


int main() {
    JEU jeu ;
    TERRAIN terrain;
    SERPENT snake;
    TIMER temps;
    PASTILLE pill;
    
    jeu.direction = 4;
    jeu.jeu_en_cours = 1;
    jeu.last_direction = 4;
    jeu.score = 0;
    jeu.touche = 0;
    jeu.jeu_en_cours = 1;

    terrain.x = 600;
    terrain.y = 400;
    terrain.fond ;

    snake.pos_x[2400];
    snake.pos_y[2400];
    snake.old_x[2400];
    snake.old_y[2400];
    snake.serpent;
    snake.segment = 10;

    temps.seconde;
    temps.minute;
    temps.seconde_actuel;
    temps.old_seconde;
    temps.timer[6];
    temps.suivant;

    pill.p;
    pill.pastille;
    pill.pastillex[5];
    pill.pastilley[5];
    
    InitialiserGraphique();
    CreerFenetre(350, 100, 1200, 800);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    temps.suivant = Microsecondes() + CYCLE;
    temps.old_seconde = (temps.suivant / 1000000) % 10;
    DessinerScene(&temps, &terrain, &snake, &pill);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0, 700, 1200, 800);
    RemplirRectangle(0, 0, 20, 20);

    while (jeu.jeu_en_cours) {
        Timer(&temps);
        Update_Timer(&temps);
        Controle(&jeu);
        Serpent(&snake, &terrain, &jeu, &pill);
        Pastille(&pill);
        Update_Score(&jeu);

    }
    



    FermerGraphique();
    return EXIT_SUCCESS;
}
/*while (jeu.jeu_en_cours) {
        Controle();

        if (!paused) {
        Timer(&temps);
        Update_Timer(&temps);
        Controle(&jeu);
        Serpent(&snake, &terrain, &jeu, &pill);
        Pastille(&pill);
        Update_Score(&jeu);
        }

        AttenteProchainePeriode();
        suivant += CYCLE;
    }*/