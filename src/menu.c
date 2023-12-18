#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

int boucle = 1;
int CouleurParNom;

void afficher_menu( titre,  selection,  facile,  moyen,  difficile) {
    ChargerImageFond("menu.png");
    dessiner_bouton(titre, "JEU DE PAIRES !", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 2);
    dessiner_bouton(selection, "Selectionnez un niveau :", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 1);
    dessiner_bouton(facile, "Facile", CouleurParNom("black"), CouleurParNom("dark green"), CouleurParNom("dark green"), 1);
    dessiner_bouton(moyen, "Moyen", CouleurParNom("black"), CouleurParNom("orange"), CouleurParNom("orange"), 1);
    dessiner_bouton(difficile, "Difficile", CouleurParNom("black"), CouleurParNom("red"), CouleurParNom("red"), 1);
}
