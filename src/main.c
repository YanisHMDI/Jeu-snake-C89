#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include <unistd.h>
#define CYCLE 10000L


int seconde=0;
int minute=0;
int seconde_actuel=0;
int old_seconde=0;
char timer[6];
unsigned long int suivant;


int go_on=1;
unsigned long int suivant;

int serpent;
int x = 600;
int y = 400;
int direction = 4;
int t;
int paused = 0;

int segment=10;
int i=0;
int pos_x[60];
int pos_y[60];
int old_x[60];
int old_y[60];

int p=0;
int pp=0;
int pomme, pommex[5], pommey[5];
int fond;

char score[4];
int Nbr;

void DessinerScene(){
    snprintf(timer,6,"%02d:%02d", minute ,seconde);
    ChoisirCouleurDessin(CouleurParComposante(91,222,122));
    RemplirRectangle(20,20,1160,700);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255)); 
    EcrireTexte(10,760,timer,2);
    serpent=ChargerSprite("serpent.png");
    fond = ChargerSprite("fond.png");
    if (paused) {
        ChoisirCouleurDessin(CouleurParComposante(255, 0, 0));
        EcrireTexte(550, 400, "PAUSE", 2);
    }

    for (i = 0; i < segment; i++){
        AfficherSprite(serpent, x-(i*20), y);
        pos_x[i]=x-(i*20);
        pos_y[i]=y;
        old_x[i]=pos_x[i];
        old_y[i]=pos_y[i];
    }
    srand(time(NULL));
    pomme=ChargerSprite("pomme.png");
    for (p = 0; p < 5; p++) {
        pommex[p] = ((rand() % (58)+1)*20);
        pommey[p] = ((rand() % (35)+1)*20);
        AfficherSprite(pomme, pommex[p],pommey[p]);
    }
    
}

void Update_Timer(){
    snprintf(timer,6,"%02d:%02d", minute, seconde);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,700,1200,800);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(10,760,timer,2);
}
void Score (){
    Nbr=(segment-10)*10;
    snprintf(score,4,"%04d0",Nbr);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,700,1200,800);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(1100,760,score,2);
}

void Update_Serpent(){
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

void AttenteProchainePeriode() {
    while (Microsecondes() < suivant) {
       
    }
}

void Terrain(){
    if (pos_x[0] >1140 || pos_x[0]<=20)
        go_on=0;
    if (pos_y[0]<40 || pos_y[0] >=680)
        go_on=0;
    
}


void Timer(){
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

void Controle() {
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

void Serpent() {
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
usleep(100000);

}
void Collision() {
    for (i = 1; i < segment; i++) {
        if (pos_x[0] == pos_x[i] && pos_y[0] == pos_y[i]) {
            go_on = 0;  
            break;
        }
    }
}

void Pomme(){

    for(pp = 0; pp < 5; ++pp){
        AfficherSprite(pomme, pommex[pp], pommey[pp]);
    }
}

int main(){

    InitialiserGraphique();
    CreerFenetre(350,100,1200,800);
    EffacerEcran(CouleurParComposante(0,0,0));
    suivant = Microsecondes()+CYCLE;
    old_seconde=(suivant/1000000)%10;
    DessinerScene();

    while (go_on) {
        Controle();

        if (!paused) {
            Timer();
            Serpent();
            Pomme();
            Collision();
            Score();
        }

        AttenteProchainePeriode();
        suivant += CYCLE;
    }


    
    FermerGraphique();
    return EXIT_SUCCESS;
}



