/* 
 * File:   enigma.h
 * Author: visiteur
 *
 * Created on 15 janvier 2020, 10:36
 */

#ifndef ENIGMA_H
#define	ENIGMA_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <sys/attribs.h>
#include <string.h>
  
#include "rotor.h"
#include "switches.h"
#include "lcd.h"
#include "led.h"
#include "boutons.h"

char enigma_cipher(char i);
void enigma_constructor(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ENIGMA_H */

