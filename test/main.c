#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "serpent.h"
#include "pastilles.h"
#include "terrain.h"
#include "jeu.h"
#include "structures.h"
#include "timer.h"



#define CYCLE 10000L



int main(void) {

    JEU jeu;
    TERRAIN terrain;
    SERPENT snake ;
    TIMER temps ;
    PASTILLE pill;

    jeu.direction = 4;
    jeu.jeu_en_cours = 4;
    jeu.last_direction = 1;
    jeu.score = 0;
    jeu.touche = 0;
    jeu.jeu_en_cours = 1;

    int old_seconde = 0;
    int suivant = 0;
    
    InitialiserGraphique();  
    CreerFenetre(350, 100, 1200, 800);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    suivant = Microsecondes() + CYCLE;
    old_seconde = (suivant / 1000000) % 10;
    DessinerScene(temps, terrain, snake);  /*la fonction doit prendre 3 parametres : DissinerScene(TIMER temps, TERRAIN terrain, SERPENT snake);*/


   while (jeu.jeu_en_cours) {
        
        Controle(&jeu);
        Serpent(&jeu);
        Pastille();
        Update_Score(&jeu);
        Update_Timer();
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}

