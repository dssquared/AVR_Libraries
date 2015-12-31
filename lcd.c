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
#define _BV(bit) (1 << (bit))

/**
* function prototypes
*/

/**
* local functions
*/
void setupLCDPorts(){
	LCD_CONTROL |= ((1 << LCD_RS) | (1 << LCD_ENABLE));          // LCD control lines as output
	LCD_DATA |= ((1 << D7) | (1 << D6) | (1 << D5) | (1 << D4)); // LCD data lines as output
}  // end setupLCDPorts()

void pulseEnable(){
	set_bit(LCD_CONTROL, LCD_ENABLE);
	_delay_us(40);
	clear_bit(LCD_CONTROL, LCD_ENABLE);
}  // end pulseEnable()

void sendNibble(byte data){
	LCD_DATA &= ~((1 << D7) | (1 << D6) | (1 << D5) | (1 << D4)); // clear only data lines w/o messing with rest of port
	if(data & _BV(4)) set_bit(LCD_DATA, D4);                      // or just use (1 << 4) etc. instead of _BV
	if(data & _BV(5)) set_bit(LCD_DATA, D5);
	if(data & _BV(6)) set_bit(LCD_DATA, D6);
	if(data & _BV(7)) set_bit(LCD_DATA, D7);
	pulseEnable();
}  // end sendNibble()

void sendByte(byte data){
	sendNibble(data);                  // send upper 4-bits, this is assuming LCD is being used in 4-bit mode
	sendNibble(data << 4);             // send lower 4-bits
}  // end sendByte()

void LCD_cmd(byte cmd){
	clear_bit(LCD_CONTROL, LCD_RS);    // R/S line 0 -> command data
	sendByte(cmd);
}  // end LCD_cmd()

void LCD_char(byte ch){
	set_bit(LCD_CONTROL, LCD_RS);     // R/S line 1 -> character data
	sendByte(ch);
}  // end LCD_char()

void LCD_init(){
	
}  // end LCD_init()

void LCD_clear(){
	
}  // end LCD_clear()

void LCD_home(){
	
}  // end LCD_home()

void LCD_goto(byte x, byte y){
	
}  // end LCD_goto()

void LCD_message(const char *text){
	
}  // end LCD_message()

void LCD_hex(int data){
	
}  // end LCD_hex()

void LCD_integer(int data){
	
}  // end LCD_integer()


/**
* public functions
*/