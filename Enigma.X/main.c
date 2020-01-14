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


#pragma config JTAGEN = OFF     
#pragma config FWDTEN = OFF

/*
 * 
 */
int main(int argc, char** argv) {
    LCD_Init();
    LCD_DisplayClear();
    rotor_rep buf = {'A',1};
    extern rotor rotor1;
    rotor1.shift = 'A';
    buf = rotor_function(&rotor1,buf);
    char buf2[10] =""; buf2[0] = buf.c;
    buf.c = 'A'; buf.mov = 1;
    buf = rotor_function(&rotor1,buf);
    buf2[1] = buf.c;
    buf2[2] = rotor1.shift;
    LCD_WriteStringAtPos(buf2,0,0);
    return (EXIT_SUCCESS);
}

