#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Timer_s {
    int seconde;
    int minute;
    int seconde_actuel;
    int old_seconde;
    char timer[6];
    unsigned long int suivant;
};

typedef struct Timer_s TIMER;

struct Terrain_s{
    int x;
    int y;
    int pos_x[60];
    int pos_y[60];
    int old_x[60];
    int old_y[60];
    int fond;
};

typedef struct Terrain_s TERRAIN;

struct Jeu_s{   
    int direction;
    int last_direction;
    int jeu_en_cours;
    int score;
    int touche;
};

typedef struct Jeu_s JEU; 

struct Serpent_s{
    int serpent;
    int segment;   
};

typedef struct Serpent_s SERPENT;

struct Pastille_s{
    int p;
    int pp;
    int pastille;
    int pastillex[5];
    int pastilley[5];
};

typedef struct Pastille_s PASTILLE;

#endif