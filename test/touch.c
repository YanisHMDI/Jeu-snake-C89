#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>

#define CYCLE 10000L
#define DELTA 1000000L
#define SEGMENT 10


typedef struct {
    int x;
    int y;
    int direction;
    int sprite;
    int paused;
} serpent;

typedef struct {
    int x;
    int y;
    int sprite;
} pomme_struct;


int ChargerFond(void) {
    int id_fond;
    id_fond = ChargerSprite("fond.png");

    return id_fond;
}


void DessinerScene(serpent* spr, int id_fond, pomme_struct* pommes) {
    int i = 0;
    ChoisirCouleurDessin(CouleurParComposante(128, 255, 0));
    RemplirRectangle(20, 20, 1160, 700);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    spr->sprite = ChargerSprite("serpent.png");

    for (i = 0; i < SEGMENT; i++) {
        AfficherSprite(spr->sprite, spr->x - (i * 20), spr->y);
    }

    srand(time(NULL));

    for (i = 0; i < 5; i++) {
        AfficherSprite(pommes[i].sprite, pommes[i].x, pommes[i].y);
    }

    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(0, 700, 1200, 800);
}


void Update_Serpent(serpent* Serpent, int* pos_x, int* pos_y, int* old_x, int* old_y) {
    int i = 0;
    AfficherSprite(Serpent->sprite, pos_x[0], pos_y[0]);
    for (i = 1; i < SEGMENT; i++) {
        pos_x[i] = old_x[i - 1];
        pos_y[i] = old_y[i - 1];
        AfficherSprite(Serpent->sprite, pos_x[i], pos_y[i]);
    }
    old_x[0] = pos_x[0];
    old_y[0] = pos_y[0];
    for (i = 1; i < SEGMENT; i++) {
        old_x[i] = pos_x[i];
        old_y[i] = pos_y[i];
    }
}


int Controle(serpent* Serpent) {
    while (ToucheEnAttente()) {
        int t;
        t = Touche();
        switch (t) {
            case XK_Left:
                if (Serpent->direction != 4) {
                    Serpent->direction = 3;
                    
                }break;
            case XK_Right:
                if (Serpent->direction != 3) {
                    Serpent->direction = 4;
                    
                }break;
            case XK_Up:
                if (Serpent->direction != 2) {
                    Serpent->direction = 1;
                    
                }break;
            case XK_Down:
                if (Serpent->direction != 1) {
                    Serpent->direction = 2;
                    
                }break;
            case XK_Escape:
                return 0;
                break;
            case XK_Return:
                
                Serpent->paused = !Serpent->paused;
                break;
        }
    }
    return 1;
}


void Attendre(int microsecondes) {
    unsigned long int attente = Microsecondes() + microsecondes;
    while (Microsecondes() < attente) {
    }
}


void Serpent(serpent* Serpent, int* pos_x, int* pos_y, int* old_x, int* old_y, int id_fond, pomme_struct* pommes) {
    int i = 0;
    if (Serpent->direction == 1) {
        pos_y[0] = old_y[0] - 20;
    }
    if (Serpent->direction == 2) {
        pos_y[0] = old_y[0] + 20;
    }
    if (Serpent->direction == 3) {
        pos_x[0] = old_x[0] - 20;
    }
    if (Serpent->direction == 4) {
        pos_x[0] = old_x[0] + 20;
    }

    for (i = 0; i < 5; i++) {
        if (pommes[i].x == pos_x[0] && pommes[i].y == pos_y[0]) {
            pommes[i].x = ((rand() % (57) + 1) * 20);
            pommes[i].y = ((rand() % (34) + 1) * 20);
        }
    }

    Update_Serpent(Serpent, pos_x, pos_y, old_x, old_y);
    Attendre(100000);
}


void Pomme(pomme_struct* pommes) {
    int i = 0;
    for (i = 0; i < 5; ++i) {
        AfficherSprite(pommes[i].sprite, pommes[i].x, pommes[i].y);
    }
}


void Update_Timer(unsigned long int debut_timer) {
    int secondes = ((Microsecondes() - debut_timer) / DELTA);
    int minutes = 0;
    char timer_text[6];

    while (secondes >= 60) {
        minutes += 1;
        secondes -= 60;
    }

    snprintf(timer_text, 6, "%02d:%02d", minutes, secondes);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(10, 720, 100, 800);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(10, 760, timer_text, 2);
}


void Score(int Nbr) {
    char score_text[5];
    snprintf(score_text, 5, "%04d0", Nbr);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(1100, 720, 1200, 800);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(1100, 760, score_text, 2);
}

int main(void) {
    unsigned long int debut_timer = Microsecondes();
    int id_fond = ChargerFond();  

    InitialiserGraphique();
    CreerFenetre(350, 100, 1200, 800);
    EffacerEcran(CouleurParComposante(0, 0, 0));
    serpent srp = {600, 400, 6,0};


    int i = 0;int pos_x[60], pos_y[60], old_x[60], old_y[60];
    for ( i = 0 ;i < 60; i++) {
        pos_x[i] = 0;
        pos_y[i] = 0;
        old_x[i] = 0;
        old_y[i] = 0;
    }

    
    pomme_struct pommes[5];
    i = 0;
    for (i = 0; i < 5; i++) {
        pommes[i].x = ((rand() % (57) + 1) * 20);
        pommes[i].y = ((rand() % (34) + 1) * 20);
        pommes[i].sprite = ChargerSprite("pomme.png");
    }

    DessinerScene(&srp, id_fond, pommes);

    while (1) {
        if (srp.paused) {
            Update_Timer(debut_timer);
            Serpent(&srp, pos_x, pos_y, old_x, old_y, id_fond, pommes);
            Pomme(pommes);
            Score((SEGMENT - 10) * 25);
        }

        if (!Controle(&srp)) {
            break;
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}
