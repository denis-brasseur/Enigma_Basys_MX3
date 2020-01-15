/* 
 * File:   main.c
 * Author: visiteur
 *
 * Created on 14 janvier 2020, 11:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>


/*
 * Personnal libraries
 */

#include "UART.h"
#include "config.h"
#include "lcd.h"
#include "switches.h"
#include "rotor.h"
#include "enigma.h"



#pragma config JTAGEN = OFF     
#pragma config FWDTEN = OFF

/*
 * 
 */


int get_number(void){
    return SWITCH0
        +  (SWITCH1<<1)
        +  (SWITCH2<<2)
        +  (SWITCH3<<3)
        +  (SWITCH4<<4)
        +  (SWITCH5<<5)
        +  (SWITCH6<<6)
        +  (SWITCH7<<7);
}
int main(int argc, char** argv) {
    enigma_constructor();
    
    while(1);
    
    return (EXIT_SUCCESS);
}

