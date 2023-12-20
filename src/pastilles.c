#include <stdlib.h>
#include <graph.h>
#include "../include/serpent.h"
#include "../include/structures.h"


void Pastille(PASTILLE *pill) {
    int pp;
    for (pp = 0; pp < 5; ++pp) {
        AfficherSprite(pill->pastille, pill->pastillex[pp], pill->pastilley[pp]);
    }
}

