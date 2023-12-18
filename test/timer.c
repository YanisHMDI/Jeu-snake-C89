#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
<<<<<<< HEAD
#include "structures.h"


#define DELTA 1000000 
=======
#include "structure.h";
#include "timer.h";

#define DELTA 1000000 // Remplacez 1000000 par la valeur appropriée en microsecondes
>>>>>>> refs/remotes/origin/master


void Update_Timer(unsigned long int debut_timer) {
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