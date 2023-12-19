#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "jeu.h"
#include "serpent.h"
#include "structures.h"


void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *snake) {
    int i = 0;
    if (snake->pos_x[0] > 1180 || snake->pos_x[0] < 20){
        jeu->jeu_en_cours = 0;
    }
    if (snake->pos_y[0] < 20 || snake->pos_y[0] > 680){
        jeu->jeu_en_cours = 0;
    }
    for (i = 1; i < snake->segment; i++) {
        if (snake->pos_x[0] == snake->pos_x[i] && snake->pos_y[0] == snake->pos_y[i])
        jeu->jeu_en_cours = 0;
    }
}

void Controle(JEU *jeu) {
    int pause = 1;
    while (ToucheEnAttente()) {
        jeu->touche = Touche();
        switch (jeu->touche) {
            case XK_Left:
                if (jeu->last_direction != 4) {
                    jeu->direction = 3;
                    jeu->last_direction = 3;
                }
                return;
            case XK_Right:
                if (jeu->last_direction != 3) {
                    jeu->direction = 4;
                    jeu->last_direction = 4;
                }
                return;
            case XK_Up:
                if ( jeu->last_direction != 2) {
                     jeu->direction = 1;
                     jeu->last_direction = 1;
                }
                return;
            case XK_Down:
                if ( jeu->last_direction != 1) {
                     jeu->direction = 2;
                    jeu->last_direction = 2;
                }
                return;
            case XK_Escape:
                 jeu->direction = 0;
                 jeu->jeu_en_cours = 0;
                

    }
}
}

void Attendre(int microsecondes) {
    unsigned long int attente = Microsecondes() + microsecondes;
    while (Microsecondes() < attente) {
    }
}

void Update_Score(JEU *jeu) {
    char score_str[10];
    snprintf(score_str, 10, "Score: %d", jeu->score);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(0, 0, 20, 20);
    RemplirRectangle(1000, 700, 1100, 800);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(1000, 760, score_str, 2);
   
}