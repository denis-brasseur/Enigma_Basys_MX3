#ifndef ROTOR_H
#define ROTOR_H
/*
typdef struct
{
    char c;     // position lettre initiale du rotor
    int num;    // numéro du rotor 1 à 5

}rotor_general;
*/


typedef struct {
    
    char shift; 
    char lettre_transform[26];
    char lettre_move;          //caractere qui entraine le rotor suivant

} rotor;

char reflector[26] = {'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'};


rotor rotor1 = {lettre_transform = {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'}, 
                lettre_move = 'R'};
//rotor1.lettre_transform= {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'};
//rotor1.lettre_move = 'R';

rotor rotor2 = {lettre_transform = {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},
                lettre_move = 'F'};
//rotor2.lettre_transform = {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'};
//rotor2.lettre_move = 'F';

rotor rotor3 = {lettre_transform = {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},
                lettre_move = 'W'};
//rotor3.lettre_transform = {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'};
//rotor3.lettre_move = 'W';

rotor rotor4 = {lettre_transform = {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'},
                lettre_move = 'K'};
//rotor4.lettre_transform = {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'};
//rotor4.lettre_move = 'K';

rotor rotor5 = {lettre_transform = {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'},
                lettre_move = 'A'};
//rotor5.lettre_transform = {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'};
//rotor5.lettre_move = 'A';


#else
#endif





