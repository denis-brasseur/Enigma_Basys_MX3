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
    
    
    char buf2[10] ="";
    rotor_rep buf = {'A',1};
    rotor *r = rotor_choice(1);
    if(r==NULL) LCD_WriteStringAtPos("holla",0,0);
    else LCD_WriteStringAtPos("hallo",0,0);
    set_initial_shift(r,'A');
    buf = rotor_function(r,buf); 
    LCD_WriteStringAtPos("hello",0,0);
    buf2[0] = buf.c;
    buf.c = 'A'; buf.mov = 1;
    buf = rotor_function(r,buf);
    buf2[1] = buf.c;
    buf2[2] = r->shift;
    LCD_DisplayClear();
    LCD_WriteStringAtPos(buf2,0,0);
    return (EXIT_SUCCESS);
}

