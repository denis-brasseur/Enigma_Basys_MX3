#include "rotor.h"

rotor_rep rotor_function(rotor r, rotor_rep i){
    rotor_rep o;
    /* �tape 1, le rotor bouge s'il le doit */
    if(i.mov==1){
        r.shift = ((r.shift+1)%26) + 'A';
    }
    /* �tape 2, la bague ext�rieure fait le d�calage */
    o.c = ((i.c + (r.shift - 'A'))%26 + 'A');
    /* �tape 3, le cablage interne fait la substitution */
    o.c = r.lettre_transform[o.c -'A'];
    /* �tape 4, si le mouvement du rotor entra�ne celui � sa gauche on le note*/
    if((r.shift == ((r.lettre_move +1)%26)+ 'A') && i.mov==1){
        o.mov = 1;
    }
    else{
        o.mov = 0;
    }
    
    return o;
}