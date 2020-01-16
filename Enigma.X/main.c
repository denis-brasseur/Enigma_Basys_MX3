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
    
//    char lcd_buffer[17]= "";
//    LCD_DisplayClear();
//    sprintf(lcd_buffer,"input = ?");
//    LCD_WriteStringAtPos(lcd_buffer,0,0);
//    sprintf(lcd_buffer,"output = ?");
//    LCD_WriteStringAtPos(lcd_buffer,1,0);
    
    init_UART();
    char c;
//    while(!BUTTON_C);
//    c = get_number() + 'A' -1;
//    sprintf(lcd_buffer,"input = %c",c);
//    LCD_WriteStringAtPos(lcd_buffer,0,0);
//    c=enigma_cipher(c);
//    sprintf(lcd_buffer,"output = %c",c);
//    LCD_WriteStringAtPos(lcd_buffer,1,0);
    while(1){
        c = read_char();
        c=enigma_cipher(c);
        write_char(c);
    }
    
    return (EXIT_SUCCESS);
}

