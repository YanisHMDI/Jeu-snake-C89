#ifndef SERPENT_H
#define SERPENT_H

#include "structures.h" 


void Serpent(JEU *jeu);
void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *serpent);
void Update_Serpent(void);


#endif /* SERPENT_H */