#include<stdlib.h>
#include<graph.h>
 
int main()
{
    InitialiserGraphique();
    CreerFenetre(10,10,600,500);
    couleur c;
    c=CouleurParNom("green");
    c=CouleurParComposante(91,222,122);
    EffacerEcran(c);
    int x = 50;
    int y = 50;
    while (1){
        x+= 10;
        y +=10;
        RemplirRectangle(x,y,10,10);
    }
    Touche();
    FermerGraphique();
    int x = 300 ;int y = 250
   return EXIT_SUCCESS;
    }