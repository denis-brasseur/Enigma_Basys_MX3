#include<iostream>
#include <string>

/*
typdef struct
{
    char c;     // position lettre initiale du rotor
    int num;    // numéro du rotor 1 à 5

}rotor_general;
*/


typdef struct 
{
    
    char shift; 
    char lettre_transform[26];
    char lettre_move;          //caractère qui entraine le rotor suivant

}rotor;

typdef struct
{
    char lettre_reflechis[26];

}reflector;



rotor rotor1;
rotor rotor2;
rotor rotor3;
rotor rotor4;
rotor rotor5;
reflector reflectorB;

rotor1.lettre_transform = {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'};
rotor1.lettre_move = 'R';
rotor1.shift = 'A'+(rotor1.shift-'A')%26 + 'A';

rotor2.lettre_transform = {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'};
rotor2.lettre_move = 'F';
rotor2.shift = 'A'+(rotor2.shift-'A')%26 + 'A';

rotor3.lettre_transform = {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'};
rotor3.lettre_move = 'W';
rotor3.shift = 'A'+(rotor3.shift-'A')%26 + 'A';

rotor4.lettre_transform = {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'};
rotor4.lettre_move = 'K';
rotor4.shift = 'A'+(rotor4.shift-'A')%26 + 'A';

rotor5.lettre_transform = {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'};
rotor5.lettre_move = 'A';
rotor5.shift = 'A'+(rotor5.shift-'A')%26 + 'A';

reflectorB.lettre_reflechis = {'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'};







