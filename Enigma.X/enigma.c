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
      
    char a = connection_table_function(i);   //passage par la table de connection
    rotor_rep buf = {a,1};
    
    for(i=0; i<3; i++){
        buf = rotor_function (R[i], buf);    //passage par les N rotors
    }
    
    buf.c = reflector_function(buf.c);       //passage sur le reflector

    for(i=2; i>=0; i--){
        buf.c = inverse_rotor_function (R[i], buf.c);    //passage par les N rotors inverses;
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
    char lcd_buffer[17] = "";
    /* etape 0 : initialisations des dépendances*/
    LCD_Init();
    LCD_DisplayClear();
    switch_initialisation();
    led_initialisation();
    led_global_extinction();
    rgb_initialisation();
    rgb_extinction();
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
            
            int i;
            for (i=0; i<5;i++){
            LED0(1);
            LED1(1);    
            LED2(1);       
            LED3(1);       
            LED4(1);       
            LED5(1);       
            LED6(1);       
            LED7(1);   
            light_red();
            DelayAprox10Us(1000);
            unput_red();
            LED0(0);
            LED1(0);    
            LED2(0);       
            LED3(0);       
            LED4(0);       
            LED5(0);       
            LED6(0);       
            LED7(0);
            DelayAprox10Us(1000);
            }
        }
        else{
            sprintf(lcd_buffer, "Rotor D = %d",get_number());
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            
            int i;
            for (i=0; i<3;i++){
            DelayAprox10Us(1000);
            light_red();
            DelayAprox10Us(1000);
            unput_red();
            light_blue();
            DelayAprox10Us(1000);
            unput_blue();
            light_green();
            DelayAprox10Us(1000);
            unput_green();
            }
            light_green();
            DelayAprox10Us(5000);
            unput_green();
            
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
            
            int i;
            for (i=0; i<5;i++){
            LED0(1);
            LED1(1);    
            LED2(1);       
            LED3(1);       
            LED4(1);       
            LED5(1);       
            LED6(1);       
            LED7(1);        
            light_red();
            DelayAprox10Us(1000);
            unput_red();
            LED0(0);
            LED1(0);    
            LED2(0);       
            LED3(0);       
            LED4(0);       
            LED5(0);       
            LED6(0);       
            LED7(0);
            DelayAprox10Us(1000);
            }
        }
        else{
            sprintf(lcd_buffer, "Rotor M = %d",get_number());
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            int i;
            for (i=0; i<3;i++){
            DelayAprox10Us(1000);
            light_red();
            DelayAprox10Us(1000);
            unput_red();
            light_blue();
            DelayAprox10Us(1000);
            unput_blue();
            light_green();
            DelayAprox10Us(1000);
            unput_green();
            }
            light_green();
            DelayAprox10Us(5000);
            unput_green();
            
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
            
            int i;
            for (i=0; i<5;i++){
            LED0(1);
            LED1(1);    
            LED2(1);       
            LED3(1);       
            LED4(1);       
            LED5(1);       
            LED6(1);       
            LED7(1);        
            light_red();
            DelayAprox10Us(1000);
            unput_red();
            LED0(0);
            LED1(0);    
            LED2(0);       
            LED3(0);       
            LED4(0);       
            LED5(0);       
            LED6(0);       
            LED7(0);
            DelayAprox10Us(1000);
            }
        }
        else{
            sprintf(lcd_buffer, "Rotor G = %d",get_number());
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            int i;
            for (i=0; i<3;i++){
            DelayAprox10Us(1000);
            light_red();
            DelayAprox10Us(1000);
            unput_red();
            light_blue();
            DelayAprox10Us(1000);
            unput_blue();
            light_green();
            DelayAprox10Us(1000);
            unput_green();
            }
            light_green();
            DelayAprox10Us(5000);
            unput_green();
        }
        DelayAprox10Us(5000);
    }
    
    /* etape 2 :  table de connections */
    int cmp, flag=3;
    char a,b;
    for(cmp=0; cmp<13; cmp++){
        if(flag==3){
            a=0, b=0;
            LCD_DisplayClear();
            sprintf(lcd_buffer,"lettre %d = ?",2*cmp+1);
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            sprintf(lcd_buffer,"lettre %d = ?",2*cmp+2);
            LCD_WriteStringAtPos(lcd_buffer,1,0);
        }
        char c=0;
        while(c==0) c=button_pressed();
        switch(c){
            case 'U': a=_get_number() + 'A' -1; flag=1; break;
            case 'D': b=_get_number() + 'A' -1; flag=2; break;
            case 'C': flag=(a!=0 && b!=0)?3:0; break;
            case 'R': flag=3; continue;
            default: flag=0;
        }
        if(flag==0) cmp--;
        if(flag==1){
            sprintf(lcd_buffer,"lettre %d = %c",2*cmp+1,a);
            LCD_WriteStringAtPos(lcd_buffer,0,0);
            cmp--;
        }
        if(flag==2){
            sprintf(lcd_buffer,"lettre %d = %c",2*cmp+2,b);
            LCD_WriteStringAtPos(lcd_buffer,1,0);
            cmp--;
        }
        if(flag==3){
            if(connection_table_constructor(a,b)){
                sprintf(lcd_buffer,"cette connection");
                LCD_WriteStringAtPos(lcd_buffer,0,0);
                sprintf(lcd_buffer,"est impossible");
                LCD_WriteStringAtPos(lcd_buffer,1,0);
                cmp--;
            }
        }
        DelayAprox10Us(5000);
    }
    
    
    /* etape 3 : positions intiales des rotors */
    int i; char c;
    for(i=0; i<3; i++){
        sprintf(lcd_buffer,"Lettre initiale");
        LCD_WriteStringAtPos(lcd_buffer,0,0);
        if(i==0){
            sprintf(lcd_buffer,"du Rotor D = ?");
            LCD_WriteStringAtPos(lcd_buffer,1,0);
        }
        if(i==1){
            sprintf(lcd_buffer,"du Rotor M = ?");
            LCD_WriteStringAtPos(lcd_buffer,1,0);
        }
        if(i==2){
            sprintf(lcd_buffer,"du Rotor G = ?");
            LCD_WriteStringAtPos(lcd_buffer,1,0);
        }
        while(!BUTTON_C);
        c = _get_number() + 'A' -1;
        set_initial_shift(R[i],c);
        sprintf(lcd_buffer,"%c",c);
        LCD_WriteStringAtPos(lcd_buffer,1,13);
        DelayAprox10Us(5000);
        LCD_DisplayClear();
    }
}


