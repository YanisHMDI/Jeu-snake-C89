#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#define CYCLE 10000L




void DessinerScene(int x, int y, int direction, int serpent, int segment, int pos_x[], int pos_y[], int old_x[], int old_y[], int pomme, int pommex[], int pommey[], int fond){
    snprintf(timer, 6, "%02d:%02d", minute, seconde);
    ChoisirCouleurDessin(CouleurParComposante(128, 255, 0));
    RemplirRectangle(20, 20, 1160, 700);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(10, 760, timer, 2);
    serpent = ChargerSprite("serpent.png");
    fond = ChargerSprite("fond.png");
    
    for (i = 0; i < segment; i++) {
        AfficherSprite(serpent, x - (i * 20), y);
        pos_x[i] = x - (i * 20);
        pos_y[i] = y;
        old_x[i] = pos_x[i];
        old_y[i] = pos_y[i];
    }
    srand(time(NULL));
    pomme = ChargerSprite("pomme.png");
    for (p = 0; p < 5; p++) {
        pommex[p] = ((rand() % (57) + 1) * 20);
        pommey[p] = ((rand() % (34) + 1) * 20);
        AfficherSprite(pomme, pommex[p], pommey[p]);
    }

    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(0, 700, 1200, 800);
}

void Update_Timer(int *seconde, int *minute){
    snprintf(timer, 6, "%02d:%02d", minute, seconde);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(10, 720, 100, 800);  
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(10, 760, timer, 2);
}

void Score(int *segment, int pos_x[], int pos_y[], int pommex[], int pommey[], int *go_on){
    Nbr = (segment - 10) * 25;
    snprintf(score, 4, "%04d0", Nbr);
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
    RemplirRectangle(1100, 720, 1200, 800);  
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(1100, 760, score, 2);
}

void Update_Serpent(int segment, int pos_x[], int pos_y[], int old_x[], int old_y[], int fond){
    AfficherSprite(fond, pos_x[segment-1], pos_y[segment-1]); 
    AfficherSprite(serpent, pos_x[0], pos_y[0]);
    for (i=1 ; i<segment ; i++){
        pos_x[i]=old_x[i-1];
        pos_y[i]=old_y[i-1];
        AfficherSprite(serpent, pos_x[i], pos_y[i]);
    }
    old_x[0]=pos_x[0];
    old_y[0]=pos_y[0];
    for (i=1 ; i<segment ; i++){
        old_x[i]=pos_x[i];
        old_y[i]=pos_y[i];
    }

}

void Terrain(int pos_x[], int pos_y[], int *go_on){
    if (pos_x[0] >1160 || pos_x[0]<=0)
        go_on=0;
    if (pos_y[0]<20 || pos_y[0] >=700)
        go_on=0;
    
}
void Timer(unsigned long int *suivant, int *old_seconde, int *x, int *y, int *direction, int pos_x[], int pos_y[], int old_x[], int old_y[], int fond, int serpent, int pomme, int pommex[], int pommey[]){
    if(Microsecondes()> suivant){
        suivant = Microsecondes()+CYCLE;
        seconde_actuel = (suivant/1000000)%10;
        if(seconde_actuel !=old_seconde){
            old_seconde = seconde_actuel;
            if(seconde == 59){
                minute=minute+1;
                seconde=0;
                Update_Timer();
            }else;{
                seconde = seconde+1;
                Update_Timer();
            }
        }
    }
}
void Controle(int *direction, int *go_on, int *paused){
    while (ToucheEnAttente()) {
        t = Touche();
        switch (t) {
            case XK_Left:
                direction = 3;
                break;
            case XK_Right:
                direction = 4;
                break;
            case XK_Up:
                direction = 1;
                break;
            case XK_Down:
                direction = 2;
                go_on = 2;
                break;
            case XK_Escape:
                direction = 0;
                break;
            case XK_Return:
                paused = !paused;
                break;
        }
    }
}


void Attendre(int microsecondes){
    unsigned long int attente = Microsecondes() + microsecondes;
    while (Microsecondes() < attente) {
        
    }
}

void Serpent(int direction, int pos_x[], int pos_y[], int old_x[], int old_y[], int pommex[], int pommey[], int *segment, int fond){
    if (direction == 1){
        pos_y[0]=old_y[0]-20;
    }
    if (direction == 2) {
        pos_y[0]=old_y[0]+20;
    }
    if (direction == 3) {
        pos_x[0]=old_x[0]-20;
    }
    if (direction == 4) {
        pos_x[0]=old_x[0]+20;
   }

    for(p=0; p<5; p++){
        if(pommex[p]==pos_x[0] && pommey[p]==pos_y[0]){
            segment+=2;
            pommex[p] = ((rand() % (65)+1)*20);
            pommey[p] = ((rand() % (29)+1)*20);
        }
    }
    Update_Serpent();
    Terrain();
    Attendre(100000);

}
void Collision(int pos_x[], int pos_y[], int *go_on, int segment){
    for (i = 1; i < segment; i++) {
        if (pos_x[0] == pos_x[i] && pos_y[0] == pos_y[i]) {
            go_on = 0;  
            break;
        }
    }
}
void Pomme(int pomme, int pommex[], int pommey[]){

    for(pp = 0; pp < 5; ++pp){
        AfficherSprite(pomme, pommex[pp], pommey[pp]);
    }
}

int main() {
    InitialiserGraphique();
    CreerFenetre(350, 100, 1200, 800);
    EffacerEcran(CouleurParComposante(0, 0, 0));

    unsigned long int suivant = Microsecondes() + CYCLE;
    int old_seconde = (suivant / 1000000) % 10;
    int go_on = 1;
    int serpent = ChargerSprite("serpent.png");
    int x = 600;
    int y = 400;
    int direction = 4;
    int t;
    int paused = 0;

    int segment = 10;
    int pos_x[60];
    int pos_y[60];
    int old_x[60];
    int old_y[60];

    srand(time(NULL));
    int pomme = ChargerSprite("pomme.png");
    int pommex[5];
    int pommey[5];

    int fond = ChargerSprite("fond.png");

    DessinerScene(x, y, direction, serpent, segment, pos_x, pos_y, old_x, old_y, pomme, pommex, pommey, fond);

    while (go_on) {
        Controle(&direction, &go_on, &paused);

        if (!paused) {
            Timer(&suivant, &old_seconde, &x, &y, &direction, pos_x, pos_y, old_x, old_y, fond, serpent, pomme, pommex, pommey);
            Serpent(direction, pos_x, pos_y, old_x, old_y, pommex, pommey, &segment, fond);
            Pomme(pomme, pommex, pommey);
            Collision(pos_x, pos_y, &go_on, segment);
            Score(&segment, pos_x, pos_y, pommex, pommey, &go_on);
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}

