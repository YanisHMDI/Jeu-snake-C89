
#include "jeu.h"

int main() {
    InitialiserGraphique();
    CreerFenetre(350,100,1200,800);
    EffacerEcran(CouleurParComposante(0,0,0));
    suivant = Microsecondes()+CYCLE;
    old_seconde=(suivant/1000000)%10;
    DessinerScene();

    while(go_on){
        Timer();
        Controle();
        Serpent();
        Pomme();
    }

    usleep(3000000);
    FermerGraphique();
    return EXIT_SUCCESS;
}
