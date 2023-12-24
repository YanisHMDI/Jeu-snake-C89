#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../include/serpent.h"
#include "../include/timer.h"
#include "../include/structures.h"
#include "../include/jeu.h"
#define CYCLE 10000L
#define X_POSITION 500
#define Y_POSITION 400

void Update_Timer(TIMER *temps){
    snprintf(temps->timer, 6, "%02d:%02d", temps->minute, temps->seconde);
    ChoisirCouleurDessin(CouleurParComposante(114,148,77));
    RemplirRectangle(0, 700, 400, 800);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(10, 760, temps->timer, 2);
}
void Timer(TIMER *temps) { 
    if (Microsecondes() > temps->suivant) {
        temps->suivant = Microsecondes() + CYCLE;
        temps->seconde_actuel = (temps->suivant / 1000000) % 10;
        if (temps->seconde_actuel != temps->old_seconde) {
            temps->old_seconde = temps->seconde_actuel;
            if (temps->seconde == 59) {
                temps->minute += 1;
                temps->seconde = 0;
                Update_Timer(temps);
            } else {
                temps->seconde = temps->seconde + 1;
                Update_Timer(temps); 
            }
        }
    }
}
void dessinerTempsFinal(unsigned long tempsEcoule) {
    
    
    int texteLargeur = 100; 
    int texteHauteur = 20;  
    
    unsigned long minutes, secondes;
    char tempsString[10];

    
    minutes = tempsEcoule / 60;
    secondes = tempsEcoule % 60;

    
    snprintf(tempsString, sizeof(tempsString), "%02lu:%02lu", minutes, secondes);

    
    ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));  
    EcrireTexte(X_POSITION, Y_POSITION, tempsString, 2);
}

