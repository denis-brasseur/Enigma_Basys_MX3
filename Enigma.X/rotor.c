#include "rotor.h"

char reflector[26] = {'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'};
rotor rotor1 = {.lettre_transform = {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'}, 
                .lettre_move = 'R'};


rotor rotor2 = {.lettre_transform = {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},
                .lettre_move = 'F'};


rotor rotor3 = {.lettre_transform = {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},
                .lettre_move = 'W'};


rotor rotor4 = {.lettre_transform = {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'},
                .lettre_move = 'K'};


rotor rotor5 = {.lettre_transform = {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'},
                .lettre_move = 'A'};


rotor_rep rotor_function(rotor *r, rotor_rep i){
    rotor_rep o;
    /* étape 1, le rotor bouge s'il le doit */
    if(i.mov==1){
        r->shift = ((r->shift+1)%26) + 'A';
    }
    /* étape 2, la bague extérieure fait le décalage */
    o.c = ((i.c + (r->shift - 'A'))%26 + 'A');
    /* étape 3, le cablage interne fait la substitution */
    o.c = r->lettre_transform[o.c -'A'];
    /* étape 3.b, le décalage de la bague extérieur réintervient, mais à l'envers */
    o.c = ((o.c + ('A' - r->shift)) % 26) + 'A';
    /* étape 4, si le mouvement du rotor entraîne celui à sa gauche on le note*/
    if((r->shift == ((r->lettre_move +1)%26)+ 'A') && i.mov==1){
        o.mov = 1;
    }
    else{
        o.mov = 0;
    }
    
    return o;
}

char reflector_function(char i){
    return reflector[i-'A'];
}