#include <proc/p32mx370f512l.h>

#include "boutons.h"

void button_initialisation(void){
    TRISAbits.TRISA15 = 1; //D Button
    TRISBbits.TRISB0 = 1; //L Button
    ANSELBbits.ANSB0 = 0; //disable analog
    TRISBbits.TRISB1 = 1; //U Button
    ANSELBbits.ANSB1 = 0; //disable analog
    TRISBbits.TRISB8 = 1; //R Button
    ANSELBbits.ANSB8 = 0; //disable analog
    TRISFbits.TRISF0 = 1; //C Button
}

int read_button(char c){
    switch(position){
        case 'C' : return PORTFbits.RF0; break;
        case 'L' : return PORTBbits.RB0; break;
        case 'R' : return PORTBbits.RB8; break;
        case 'U' : return PORTBbits.RB1; break;
        case 'D' : return PORTAbits.RA15; break;
        default : return -1;
    }
}