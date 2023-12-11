#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define WINDOW_WIDTH 800 /*Remplacez par la largeur souhaitée*/
#define WINDOW_HEIGHT 500 /*Remplacez par la hauteur souhaitée*/
int rows;
int cols;
int couleurTexte;
int couleurFond;
int couleurBordure;
int epaisseur;
int x;
int y;
int x, y, width, height;
int boucle = 1;

typedef struct {
    
} Zone;

int game() {
    /*Fonction game à implémenter*/ 
    /*Retourne 1 si le jeu a réussi, 0 sinon*/
    return 1; /*À remplacer avec l'implémentation réelle*/
}

void dessiner_bouton(Zone zone, char* texte) {
    /*Implémentation de dessiner_bouton*/
    /*À remplir avec le code nécessaire*/
}

int check_zone(Zone zone) {
    /*Implémentation de check_zone*/
    /*À remplir avec le code nécessaire*/
    return 0; /*À remplacer avec l'implémentation réelle*/
}

void afficher_menu(Zone titre, Zone selection, Zone facile, Zone moyen, Zone difficile) {
    ChargerImageFond("menu.png");
    dessiner_bouton(titre, "JEU DE PAIRES !", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 2);
    dessiner_bouton(selection, "Selectionnez un niveau :", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 1);
    dessiner_bouton(facile, "Facile", CouleurParNom("black"), CouleurParNom("dark green"), CouleurParNom("dark green"), 1);
    dessiner_bouton(moyen, "Moyen", CouleurParNom("black"), CouleurParNom("orange"), CouleurParNom("orange"), 1);
    dessiner_bouton(difficile, "Difficile", CouleurParNom("black"), CouleurParNom("red"), CouleurParNom("red"), 1);

    while (boucle) {
        SourisPosition();
        if (SourisCliquee()) {
            if (check_zone(facile, 396.3, 219)) {
                if(game(2, 2)) {
                    afficher_menu(titre, selection, facile, moyen, difficile);
                } else {
                    boucle = 0;
                }
            }
            if (check_zone(moyen, 395.3, 287.2)) {
                if (game(4, 4)) {
                    afficher_menu(titre, selection, facile, moyen, difficile);
                } else {
                    boucle = 0;
                }
            }
            if (check_zone(difficile, 395.1, 354.6)) {
                if (game(8, 8)) {
                    afficher_menu(titre, selection, facile, moyen, difficile);
                } else {
                    boucle = 0;
                }
            }
        }
    }
}

int main(void) {
    InitialiserGraphique();
    CreerFenetre(375, 175, WINDOW_WIDTH, WINDOW_HEIGHT);

    Zone titre = {490, 60, 260, 55};
    Zone selection = {42, 300, 230, 35};
    Zone facile = {42, 375, 85, 35};
    Zone moyen = {42, 450, 85, 35};
    Zone difficile = {42, 525, 85, 35};

    afficher_menu(titre, selection, facile, moyen, difficile);
    
    FermerGraphique();
    return EXIT_SUCCESS;
}
