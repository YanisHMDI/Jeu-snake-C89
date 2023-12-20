#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include <unistd.h>

#define CYCLE 10000L
#define DELTA 1000000L
#define SEGMENT 10

typedef struct {
    int x;
    int y;
    int direction;
    int sprite;
} Serpent;

int paused = 0;
int pos_x[60];
int pos_y[60];
int old_x[60];
int old_y[60];
int pomme, pommex[5], pommey[5];

char score[5];
int Nbr;

void DessinerScene(Serpent *spr) {
    int i = 0;
    ChoisirCouleurDessin(CouleurParComposante(128, 255, 0));
    RemplirRectangle(20, 20, 1160, 700);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    spr->sprite = ChargerSprite("serpent.png");
    int fond = ChargerSprite("fond.png");

    for (i = 0; i < SEGMENT; i++) {
        AfficherSprite(spr->sprite, spr->x - (i * 20), spr->y);
        pos_x[i] = spr->x - (i * 20);
        pos_y[i] = spr->y;
        old_x[i] = pos_x[i];
        old_y[i] = pos_y[i];
    }

    srand(time(NULL));
    pomme = ChargerSprite("pomme.png");
    for (i = 0; i < 5; i++) {
        pommex[i] = ((rand() % (57) + 1) * 20);
        pommey[i] = ((rand() % (34) + 1) * 20);
        AfficherSprite(pomme, pommex[i], pommey[i]);
    }
}

void UpdateTimer(unsigned long int debut_timer) {
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

void Score() {
    Nbr = (SEGMENT - 10) * 25;
    snprintf(score, 5, "%04d0", Nbr);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(1100, 720, 1200, 800);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(1100, 760, score, 2);
}

void UpdateSerpent(int fond, Serpent *Serpent) {
    int i = 0;
    AfficherSprite(fond, pos_x[SEGMENT - 1], pos_y[SEGMENT - 1]);
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

void Attendre(int microsecondes) {
    unsigned long int attente = Microsecondes() + microsecondes;
    while (Microsecondes() < attente) {
    }
}

void Pomme() {
    int i = 0;
    for (i = 0; i < 5; ++i) {
        AfficherSprite(pomme, pommex[i], pommey[i]);
    }
}

void Collision() {
    int i;
    for (i = 1; i < SEGMENT; i++) {
        if (pos_x[0] == pos_x[i] && pos_y[0] == pos_y[i]) {
            exit(0);
        }
    }
}

void Controle(Serpent *serpent) {
    int t;
    while (ToucheEnAttente()) {
        t = Touche();
        switch (t) {
        case XK_Left:
            if (serpent->direction != 4) {
                serpent->direction = 3;
            }
            break;
        case XK_Right:
            if (serpent->direction != 3) {
                serpent->direction = 4;
            }
            break;
        case XK_Up:
            if (serpent->direction != 2) {
                serpent->direction = 1;
            }
            break;
        case XK_Down:
            if (serpent->direction != 1) {
                serpent->direction = 2;
            }
            break;
        case XK_Escape:
            serpent->direction = 0;
            break;
        case XK_Return:
            paused = !paused;
            break;
        }
    }
}

void SerpentMovement(Serpent *serpent) {
    if (serpent->direction == 1) {
        pos_y[0] = old_y[0] - 20;
    }
    if (serpent->direction == 2) {
        pos_y[0] = old_y[0] + 20;
    }
    if (serpent->direction == 3) {
        pos_x[0] = old_x[0] - 20;
    }
    if (serpent->direction == 4) {
        pos_x[0] = old_x[0] + 20;
    }

    for (p = 0; p < 5; p++) {
        if (pommex[p] == pos_x[0] && pommey[p] == pos_y[0]) {
            SEGMENT += 2;
            pommex[p] = ((rand() % (65) + 1) * 20);
            pommey[p] = ((rand() % (29) + 1) * 20);
        }
    }

    UpdateSerpent(0, serpent);
    Attendre(100000);
}

int main() {
    InitialiserGraphique();
    CreerFenetre(350, 100, 1200, 800);
    EffacerEcran(CouleurParComposante(0, 0, 0));

    unsigned long int debut_timer = Microsecondes();
    Serpent srp = {600, 400, 4};

    DessinerScene(&srp);

    while (1) {
        Controle(&srp);

        if (!paused) {
            UpdateTimer(debut_timer);
            SerpentMovement(&srp);
            Pomme();
            Collision();
            Score();
        }

        Attendre(CYCLE);
        debut_timer += CYCLE;
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}
