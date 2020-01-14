#include "rotor.h"

rotor_rep rotor_function(rotor r, rotor_rep i){
    rotor_rep o;
    /* étape 1, le rotor bouge s'il le doit */
    if(i.mov==1){
        r.shift = ((r.shift+1)%26) + 'A';
    }
    /* étape 2, la bague extérieure fait le décalage */
    o.c = ((i.c + (r.shift - 'A'))%26 + 'A');
    /* étape 3, le cablage interne fait la substitution */
    o.c = r.lettre_transform[o.c -'A'];
    /* étape 4, si le mouvement du rotor entraîne celui à sa gauche on le note*/
    if((r.shift == ((r.lettre_move +1)%26)+ 'A') && i.mov==1){
        o.mov = 1;
    }
    else{
        o.mov = 0;
    }
    
    return o;
}