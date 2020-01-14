#ifndef ROTOR_H
#define ROTOR_H

#include "led.h"

typedef struct {
    
    char shift;                 //caract�re visible depuis la fen�tre au dessus du rotor
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
void connection_table_constructor(char i, char j);


#endif /* ROTOR_H */





