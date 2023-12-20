#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../include/jeu.h"
#include "../include/serpent.h"
#include "../include/structures.h"



void Serpent(SERPENT *snake, TERRAIN *terrain, JEU *jeu, PASTILLE *pill) {

    if (jeu->direction == 1 && jeu->direction != 2 ){
        snake->pos_y[0]=snake->old_y[0]-20;
    }
    if (jeu->direction == 2 && jeu->direction !=  1) {
        snake->pos_y[0]=snake->old_y[0]+20;
    }
    if (jeu->direction == 3 && jeu->direction != 4) {
        snake->pos_x[0]=snake->old_x[0]-20;
    }
    if (jeu->direction == 4 && jeu->direction != 3) {
        snake->pos_x[0]=snake->old_x[0]+20;
   }

    for(pill->p=0; pill->p<5; pill->p++){
        if(pill->pastillex[pill->p]==snake->pos_x[0] && pill->pastilley[pill->p]==snake->pos_y[0]){
            snake->segment+=2;
            pill->pastillex[pill->p] = ((rand() % (57)+1)*20);
            pill->pastilley[pill->p] = ((rand() % (34)+1)*20);
            jeu->score += 5;
            Update_Score(jeu);
        }
    }

    Update_Serpent(snake,terrain);
    ConditionDefaite(jeu,terrain,snake);
    Attendre(100000);

}



void Update_Serpent(SERPENT *snake, TERRAIN *terrain){
    int i;

    AfficherSprite(terrain->fond, snake->pos_x[snake->segment-1], snake->pos_y[snake->segment-1]);
    AfficherSprite(snake->serpent, snake->pos_x[0], snake->pos_y[0]);
    for (i=1 ; i<snake->segment ; i++){
        snake->pos_x[i]=snake->old_x[i-1];
        snake->pos_y[i]=snake->old_y[i-1];
        AfficherSprite(snake->serpent, snake->pos_x[i], snake->pos_y[i]);
    }
    snake->old_x[0]=snake->pos_x[0];
    snake->old_y[0]=snake->pos_y[0];
    for (i=1 ; i<snake->segment ; i++){
        snake->old_x[i]=snake->pos_x[i];
        snake->old_y[i]=snake->pos_y[i];
    }

}