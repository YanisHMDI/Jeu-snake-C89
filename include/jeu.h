#ifndef JEU_H
#define JEU_H

#include "structures.h"



void Controle(JEU *jeu);
void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *snake);
void Update_Score(JEU *jeu);
void Attendre(int microsecondes);
void fin_de_jeu(JEU *jeu, TIMER *temps);
void dessinerScoreFin(int score);
void dessinerTempsFinal(unsigned long tempsEcoule);



#endif
