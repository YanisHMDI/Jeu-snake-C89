#include<stdlib.h>
#include<graph.h>
 
int main()
{
    InitialiserGraphique();
    CreerFenetre(10,10,1000,800);
    couleur c;
    c=CouleurParNom("green");
    c=CouleurParComposante(91,222,122);
    EffacerEcran(c);
    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}