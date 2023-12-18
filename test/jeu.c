#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "serpent.h"
#include "structures.h"
#include "jeu.h"



void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *serpent) {
    int i;

    if (terrain->pos_x[0] > 1140 || terrain->pos_x[0] <= 20)
        jeu->jeu_en_cours = 0;
    if (terrain->pos_y[0] < 40 || terrain->pos_y[0] >= 680)
        jeu->jeu_en_cours = 0;

    for (i = 1; i < serpent->segment; i++) {
        if (terrain->pos_x[0] == terrain->pos_x[i] && terrain->pos_y[0] == terrain->pos_y[i])
            jeu->jeu_en_cours = 0;
    }
}




void Controle(JEU *jeu) {
    jeu->direction = 0;
    jeu->last_direction = 0;
    jeu->jeu_en_cours = 1;

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
                if (jeu->last_direction != 2) {
                    jeu->direction = 1;
                    jeu->last_direction = 1;
                }
                return;
            case XK_Down:
                if (jeu->last_direction != 1) {
                    jeu->direction = 2;
                    jeu->last_direction = 2;
                }
                return;
            case XK_Escape:
                jeu->direction = 0;
                jeu->jeu_en_cours = 0;
                return;
            case XK_p:
                jeu->direction = 0;
                
                return;
            
        }
    }
}
void Attendre(int microsecondes) {
    unsigned long int attente = Microsecondes() + microsecondes;
    while (Microsecondes() < attente) {
    }
}

void Update_Score(JEU *jeu) {
    int score = 0;
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(1000, 800, 1200, 800);
    char score_str[10];
    snprintf(score_str, 10, "SCORE: %d", score);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(1000, 760, score_str, 2);
}