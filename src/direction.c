#include "struct1.c"
#include "graph.h"
#include "time.h"

void controle_jeu(struct Serpent *serpent){
    while(ToucheEnAttente()){
        int touche = Touche();
        if (touche == XK_Up && serpent ->direction !='b'){
            serpent->diretion ='h' ;
            break;
        }
        if (touche ==XK_Down && serpent->direction !='h'){
            serpent->direction ='b'
            break;
        }
        if (touche==XK_Left && serpent->direction !='d'){
            serpent->direction ='g'
            break
        }
        if (touche==XK_Right && serpent->direction !='g'){
            serpent->direction ='d'
            break
        }
    }
}