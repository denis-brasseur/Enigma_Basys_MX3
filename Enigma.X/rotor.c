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


char tab_connection[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void light_value(char c){
    led_global_extinction();
    if(c&1) LED0(1);
    if((c>>1)&1) LED1(1);
    if((c>>2)&1) LED2(1);
    if((c>>3)&1) LED3(1);
    if((c>>4)&1) LED4(1);
    if((c>>5)&1) LED5(1);
    if((c>>6)&1) LED6(1);
    if((c>>7)&1) LED7(1);
}


rotor_rep rotor_function(rotor *r, rotor_rep i){
    led_initialisation();
    led_global_extinction();
    rotor_rep o;
    /* �tape 1, le rotor bouge s'il le doit */
    if(i.mov==1){
        r->shift = (r->shift+1);
        if(r->shift > 'Z') r->shift = r->shift - 26;
    }
    /* �tape 2, la bague ext�rieure fait le d�calage */
    o.c = i.c + (r->shift - 'A');
    if(o.c > 'Z') o.c = o.c - 26;
    
    /* �tape 3, le cablage interne fait la substitution */
    o.c = r->lettre_transform[o.c -'A'];
    
    //if(o.c == 'M') LED0(1);
    //else LED1(1);
    /* �tape 3.b, le d�calage de la bague ext�rieur r�intervient, mais � l'envers */
    o.c = o.c + ('A' - r->shift);
    if(o.c < 'A') o.c = o.c + 26;
    light_value(r->shift);
    /* �tape 4, si le mouvement du rotor entra�ne celui � sa gauche on le note*/
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

char connection_table_function(char i){
    return tab_connection[i-'A'];
}

void connection_table_constructor(char i, char j){

    if (tab_connection[i-'A']==i && tab_connection[j-'A']==j)
    {
        tab_connection[i-'A']=j;
        tab_connection[j-'A']=i;
    }

}