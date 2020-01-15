#include "enigma.h"

rotor* R[3] = {NULL,NULL,NULL};

#define RotorD R[0]
#define RotorM R[1]
#define RotorG R[2]

void led_number(unsigned char val){
    LED0(val%2);
    val /= 2;
    LED1(val%2);
    val /= 2;
    LED2(val%2);
    val /= 2;
    LED3(val%2);
    val /= 2;
    LED4(val%2);
    val /= 2;
    LED5(val%2);
    val /= 2;
    LED6(val%2);
    val /= 2;
    LED7(val%2);
}

char enigma_cipher(char i){               // i lettre Ã  chiffrer
    
    //temporaire
    led_initialisation();
    led_global_extinction();
    
    //LED1(1);
    R[0] = rotor_choice(1);
    R[1] = rotor_choice(2);
    R[2] = rotor_choice(3);
    
    R[0]->shift = 'A';
    R[1]->shift = 'A';
    R[2]->shift = 'A';
    
    
    
    
    char a = connection_table_function(i);   //passage par la table de connection
    rotor_rep buf = {a,1};
    for(i=0; i<3; i++){
        buf = rotor_function (R[i], buf);    //passage par les N rotors
    }

    buf.c = reflector_function(buf.c);       //passage sur le reflector

    for(i=2; i>=0; i--){
        buf.c = inverse_rotor_function (R[i], buf.c);    //passage par les N rotors inverses
    }

    a = connection_table_function(buf.c);  //repassage par la table de connection

    return a;
} 


int _get_number(void){
    return SWITCH0
        +  (SWITCH1<<1)
        +  (SWITCH2<<2)
        +  (SWITCH3<<3)
        +  (SWITCH4<<4)
        +  (SWITCH5<<5)
        +  (SWITCH6<<6)
        +  (SWITCH7<<7);
}

void enigma_constructor(void){
    char lcd_buffer[16] = "";
    /* etape 0 : initialisations des dépendances*/
    LCD_Init();
    LCD_DisplayClear();
    switch_initialisation();
    led_initialisation();
    led_global_extinction();
    buttons_initialisation();
    
    /* etape 1 : choisir les rotors*/
    /* etape 1.1 : rotor D */
    while(RotorD == NULL){
        LCD_DisplayClear();
        sprintf(lcd_buffer, "Rotor D = ?");
        LCD_WriteStringAtPos(lcd_buffer,0,0);
        while(!BUTTON_C) ;
        RotorD = rotor_choice(_get_number());
        if(RotorD==RotorM || RotorD == RotorG) RotorD = NULL;
        if(RotorD==NULL){
            sprintf(lcd_buffer,"Ce Rotor n'est");
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            sprintf(lcd_buffer,"pas disponible.");
            LCD_WriteStringAtPos(lcd_buffer,1,0);
        }
        else{
            sprintf(lcd_buffer, "Rotor D = %d",get_number());
            LCD_WriteStringAtPos(lcd_buffer,0,0);
        }
        DelayAprox10Us(5000);
    }
    
    /* etape 1.2 : rotor M */
    while(RotorM == NULL){
        LCD_DisplayClear();
        sprintf(lcd_buffer, "Rotor M = ?");
        LCD_WriteStringAtPos(lcd_buffer,0,0);
        while(!BUTTON_C) ;
        RotorM = rotor_choice(_get_number());
        if(RotorM==RotorD || RotorM == RotorG) RotorM = NULL;
        if(RotorM==NULL){
            sprintf(lcd_buffer,"Ce Rotor n'est");
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            sprintf(lcd_buffer,"pas disponible.");
            LCD_WriteStringAtPos(lcd_buffer,1,0);
        }
        else{
            sprintf(lcd_buffer, "Rotor M = %d",get_number());
            LCD_WriteStringAtPos(lcd_buffer,0,0);
        }
        DelayAprox10Us(5000);
    }
    
    /* etape 1.3 : rotor G */
    while(RotorG == NULL){
        LCD_DisplayClear();
        sprintf(lcd_buffer, "Rotor G = ?");
        LCD_WriteStringAtPos(lcd_buffer,0,0);
        while(!BUTTON_C) ;
        RotorG = rotor_choice(_get_number());
        if(RotorG==RotorD || RotorG == RotorM) RotorG = NULL;
        if(RotorG==NULL){
            sprintf(lcd_buffer,"Ce Rotor n'est");
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            sprintf(lcd_buffer,"pas disponible.");
            LCD_WriteStringAtPos(lcd_buffer,1,0);
        }
        else{
            sprintf(lcd_buffer, "Rotor G = %d",get_number());
            LCD_WriteStringAtPos(lcd_buffer,0,0);
        }
        DelayAprox10Us(5000);
    }
    
    /* etape 2 :  table de connections */
    int cmp;
    for(cmp=0; cmp<13; cmp++){
        char a,b;
        LCD_DisplayClear();
        sprintf(lcd_buffer,"lettre %d = ?",2*cmp+1);
        LCD_WriteStringAtPos(lcd_buffer,0,0);
        sprintf(lcd_buffer,"lettre %d = ?",2*cmp+2);
        LCD_WriteStringAtPos(lcd_buffer,1,0);
        while(!BUTTON_U);
        a = _get_number() + 'A' -1;
        sprintf(lcd_buffer,"lettre %d = %c",2*cmp+1,a);
        LCD_WriteStringAtPos(lcd_buffer,0,0);
        while(!BUTTON_D);
        b = _get_number() + 'A' -1;
        sprintf(lcd_buffer,"lettre %d = %c",2*cmp+2,b);
        LCD_WriteStringAtPos(lcd_buffer,1,0);
        DelayAprox10Us(5000);
        connection_table_constructor(a,b);
    }
}
