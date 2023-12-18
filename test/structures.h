#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Serpent_s {
    int serpent;
    int segment;
} SERPENT;

typedef struct Terrain_s {
    int x;
    int y;
    int pos_x[60];
    int pos_y[60];
    int old_x[60];
    int old_y[60];
    int fond;
} TERRAIN;

typedef struct Timer_s {
    int seconde;
    int minute;
    int seconde_actuel;
    int old_seconde;
    char timer[6];
    unsigned long int suivant;
} TIMER;

typedef struct Pastille_s {
    int p;
    int pp;
    int pastille;
    int pastillex[5];
    int pastilley[5];
} PASTILLE;

typedef struct {
    int direction;
    int jeu_en_cours;
    int last_direction;
    int score;
    int touche;
    TERRAIN terrain;
    SERPENT snake;
} JEU;

#endif
