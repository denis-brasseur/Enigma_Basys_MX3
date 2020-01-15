/* 
 * File:   boutons.h
 * Author: visiteur
 *
 * Created on 15 janvier 2020, 11:14
 */

#ifndef BOUTONS_H
#define	BOUTONS_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#define BUTTON_C read_button('C')
#define BUTTON_L read_button('L')
#define BUTTON_R read_button('R')
#define BUTTON_U read_button('U')
#define BUTTON_D read_button('D')
    
    void button_initialisation();
    int read_button(char c);

#ifdef	__cplusplus
}
#endif

#endif	/* BOUTONS_H */

