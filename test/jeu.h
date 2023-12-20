#ifndef JEU_H
#define JEU_H

#include "structures.h"



void Controle(JEU *jeu);
void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *snake);
void Update_Score(JEU *jeu);
void Attendre(int microsecondes);


#endif
