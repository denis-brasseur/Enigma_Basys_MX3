#ifndef ROTOR_H
#define ROTOR_H

#include "led.h"

typedef struct {
    
    char shift;                 //caractère visible depuis la fenêtre au dessus du rotor
    char lettre_transform[26]; // tableau correspondant au cablage interne du rotor
    char lettre_move;          //caractere qui entraine le rotor suivant

} rotor;


struct adhoc {
    char c;
    char mov;
};
typedef struct adhoc rotor_rep;




rotor_rep rotor_function(rotor *r, rotor_rep i);
char reflector_function(char i);
char connection_table_function(char* connection_table, char i);

#endif /* ROTOR_H */





