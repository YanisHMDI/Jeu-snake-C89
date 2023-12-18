#ifndef JEU_H
#define JEU_H


#include "structures.h"



void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *serpent);
void Attendre(int microsecondes);
void Controle(JEU *jeu);
void Update_Score(JEU *jeu);

#endif /* JEU_H*/

