#include "serpent.h"
#include "jeu.h"
#include "structures.h"




void Serpent(JEU *jeu) {
    int score = 0;
    int i = 0;
    int segment = 10;
    int direction = 4;

    int p = 0;

    int pos_x[60];
    int pos_y[60];
    int old_x[60];
    int old_y[60];

    int pastillex[5], pastilley[5];

    
    ConditionDefaite(jeu, &(jeu->terrain), &(jeu->snake));;
    for (p = 0; p < 5; p++) {
        if (pastillex[p] == pos_x[0] && pastilley[p] == pos_y[0]) {
            segment += 2;
            pastillex[p] = ((rand() % (57) + 1) * 20);
            pastilley[p] = ((rand() % (34) + 1) * 20);
            score += 5;
            Update_Score(jeu);
        }
    }
    ConditionDefaite(jeu, &(jeu->terrain), &(jeu->snake));
    Update_Serpent();
    Attendre(100000);
}

void Update_Serpent(void) {
    int fond;
    int serpent;
    int segment = 10;

    int i;

    int pos_x[60];
    int pos_y[60];
    int old_x[60];
    int old_y[60];

    
    AfficherSprite(fond, pos_x[segment-1], pos_y[segment-1]);
    AfficherSprite(serpent, pos_x[0], pos_y[0]);

    for (i = 1; i < segment; i++) {
        pos_x[i] = old_x[i - 1];
        pos_y[i] = old_y[i - 1];
        AfficherSprite(serpent, pos_x[i], pos_y[i]);
    }

    old_x[0] = pos_x[0];
    old_y[0] = pos_y[0];

    for (i = 1; i < segment; i++) {
        old_x[i] = pos_x[i];
        old_y[i] = pos_y[i];
    }
}

