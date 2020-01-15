#include "enigma.h"
#include "rotor.h"

rotor* R[3] = {NULL,NULL,NULL};

#define RotorD R[0]
#define RotorM R[1]
#define RotorG R[2]

char enigma_cifer(char i){               // i lettre à chiffrer

    char a = connection_table_function(i);   //passage par la table de connection

    for(i=0; i<3; i++){
        buf = rotor_rep (rotor* R[i], a);    //passage par les N rotors
    }

    buf.c = reflector_function(buf.c);       //passage sur le reflector

    for(i=2; i>=0; i--){
        buf.c = inverse_rotor_function (rotor* R[i], buf.c);    //passage par les N rotors invees
    }

    a = connection_table_function(buf.c);  //repassage par la table de connection

    return a;
} 
