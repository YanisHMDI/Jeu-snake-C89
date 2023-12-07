#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
<<<<<<< HEAD


void afficher_menu(zone titre, zone selection, zone facile, zone moyen, zone difficile, zone quitter) {
    ChargerImageFond("./img/backgrounds/menu.png");
    dessiner_bouton(titre, "JEU DE SERPENT", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 2);
=======
#include"../include/main.h"
#include"../include/game.h"

void afficher_menu(zone titre, zone selection, zone facile, zone moyen, zone difficile, zone quitter) {
    ChargerImageFond("./img/backgrounds/menu.gif");
    dessiner_bouton(titre, "JEU DU SERPENT !", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 2);
>>>>>>> @{u}
    dessiner_bouton(selection, "Selectionnez un niveau :", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 1);
    dessiner_bouton(facile, "Facile", CouleurParNom("black"), CouleurParNom("dark green"), CouleurParNom("dark green"), 1);
    dessiner_bouton(moyen, "Moyen", CouleurParNom("black"), CouleurParNom("orange"), CouleurParNom("orange"), 1);
    dessiner_bouton(difficile, "Difficile", CouleurParNom("black"), CouleurParNom("red"), CouleurParNom("red"), 1);
    dessiner_bouton(quitter, "QUITTER", CouleurParNom("red"), CouleurParNom("red"), CouleurParNom("white"), 1);
}
<<<<<<< HEAD
void menu(void) {
=======

void menu(void){
>>>>>>> @{u}
    zone titre = {490, 60, 260, 55};
    zone selection = {42, 300, 230, 35};
    zone facile = {42, 375, 85, 35};
    zone moyen = {42, 450, 85, 35};
    zone difficile = {42, 525, 85, 35};
    zone quitter = {42, 605, 100, 35};
    afficher_menu(titre, selection, facile, moyen, difficile, quitter);
    int boucle = 1;
<<<<<<< HEAD
    while (boucle) {
        SourisPosition();
        if (SourisCliquee()) {
	    if (check_zone(facile, _X, _Y)) {
	    	if(game(2, 2)) {
		    afficher_menu(titre, selection, facile, moyen, difficile, quitter);
		} else {
		    boucle = 0;
		}
	    }
	    if (check_zone(moyen, _X, _Y)) {
	    	if (game(4, 4)) {
		    afficher_menu(titre, selection, facile, moyen, difficile, quitter);
		} else {
		    boucle = 0;
		}
	    }
	    if (check_zone(difficile, _X, _Y)) {
	    	if (game(8, 8)) {
		    afficher_menu(titre, selection, facile, moyen, difficile, quitter);
		} else {
		    boucle = 0;
		}
	    }
            if (check_zone(quitter, _X, _Y)) boucle = 0;
        }
    }
}
=======
    while (boucle){
        SourisPosition();
        if (SourisCliquee()) {
            if (check_zone(facile, _X, _Y)){
                if(game(2, 2)) {
                    afficher_menu(titre, selection, facile, moyen, difficile, quitter);
                } else {
                    boucle = 0;
                }
            }
            if (check_zone(moyen, _X, _Y)) {
                if (game(4, 4)) {
                    afficher_menu(titre, selection, facile, moyen, difficile, quitter);
                } else {
                    boucle = 0;
                }
            }
            if (check_zone(difficile, _X, _Y)) {
                if (game(8, 8)) {
                    afficher_menu(titre, selection, facile, moyen, difficile, quitter);
                } else {
                    boucle = 0;
                }
            }
            if (check_zone(quitter, _X, _Y)) boucle = 0;
        }
    }
}
>>>>>>> @{u}
