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
//    led_initialisation();
//    led_global_extinction();
//    LED1(1);
    
    LCD_Init();
    switch_initialisation();
    LCD_DisplayClear();
    char lcd_buf[16] = "";
    
    sprintf(lcd_buf,"input = ?");
    LCD_WriteStringAtPos(lcd_buf,0,0);
    sprintf(lcd_buf,"output = ?");
    LCD_WriteStringAtPos(lcd_buf,1,0);
    
    while(!BUTTON_C);
    char c = get_number() -1 + 'A';
    sprintf(lcd_buf,"input = %c",c);
    LCD_WriteStringAtPos(lcd_buf,0,0);
    
    c = enigma_cipher(c);
    sprintf(lcd_buf,"output = %c",c);
    LCD_WriteStringAtPos(lcd_buf,1,0);
    
    while(1);
    
    return (EXIT_SUCCESS);
}

