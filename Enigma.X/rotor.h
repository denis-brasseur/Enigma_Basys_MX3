#ifndef ROTOR_H
#define ROTOR_H



typedef struct {
    
    char shift; 
    char lettre_transform[26];
    char lettre_move;          //caractere qui entraine le rotor suivant

} rotor;

char reflector[26] = {'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'};

struct adhoc {
    char c;
    char mov;
};
typedef struct adhoc rotor_rep;

rotor rotor1 = {lettre_transform = {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'}, 
                lettre_move = 'R'};


rotor rotor2 = {lettre_transform = {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},
                lettre_move = 'F'};


rotor rotor3 = {lettre_transform = {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},
                lettre_move = 'W'};


rotor rotor4 = {lettre_transform = {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'},
                lettre_move = 'K'};


rotor rotor5 = {lettre_transform = {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'},
                lettre_move = 'A'};


rotor_rep rotor_function(rotor r, rotor_rep i);

#else
#endif





