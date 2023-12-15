#include <stdlib.h>
#include <graph.h>
#include "serpent.h"
#include "structure.h"



/*  void Pastille(pill) --> il faut indiquer le type de "pill" en parametres, 
    de plus, vous le passez en parametre mais vous ne l'utilisez pas dans la fonction donc void Pastille(void)
*/
void Pastille(void) {
    int pp;
    int pastille, pastillex[5], pastilley[5];
    for (pp = 0; pp < 5; ++pp) {
        AfficherSprite(pastille, pastillex[pp], pastilley[pp]);
    }
}