/*****************************************************
****  Title: lcd.c                                ****
****  Author: David Schwehr 2015                  ****
****  File:                                       ****
****  Software:                                   ****
****  Target:                                     ****

 DESCRIPTION
 USAGE
******************************************************/
 

/**
* includes
*/
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "lcd.h"

/**
* constants/macros
*/

/**
* function prototypes
*/

/**
* local functions
*/
void setupLCDPorts(){
	LCD_CONTROL |= ((1 << LCD_RS) | (1 << LCD_ENABLE)); // set pins as output
	LCD_DATA |= ((1 << D7) | (1 << D6) | (1 << D5) | (1 << D4)); // LCD data lines as output
}  // end setupLCDPorts()

void pulseEnable(){
	
}  // end pulseEnable()
/**
* public functions
*/