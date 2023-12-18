#ifndef JEU_H
#define JEU_H

<<<<<<< HEAD

#include "structures.h"



void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *serpent);
void Attendre(int microsecondes);
void Controle(JEU *jeu);
void Update_Score(JEU *jeu);

#endif /* JEU_H*/

=======
//il faut mettre aussi les parametres des fonctions 
void Controle(JEU jeu);
void ConditionDefaite(JEU jeu, TERRAIN terrain, SERPENT serpent);
void Update_Score(JEU jeu);
void Attendre(int microsecondes);

#endif
>>>>>>> refs/remotes/origin/master
