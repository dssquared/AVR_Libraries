/***********************************************************
****  Title: C include file for LCD library (lcd.c)     ****
****  Author: David Schwehr 2015                        ****
****  File:                                             ****
****  Software:                                         ****
****  Target:                                           ****
************************************************************/
/**
@mainpage
@author
@file
@code
@brief
@see
@version
@copyright
 */

#ifndef LCD_H
#define LCD_H

/**
* @name definitions
*/
#ifndef LCD_CONTROL               // LCD control port of MCU //
#define LCD_CONTROL     PORTB
#endif
#ifndef LCD_DATA                     // LCD data port of MCU //
#define LCD_DATA        PORTD
#endif
#ifndef LCD_RS                    // LCD register select pin //
#define LCD_RS          0
#endif
#ifndef LCD_ENABLE                         // LCD enable pin //
#define LCD_ENABLE      1
#endif
#ifndef D4                               // LCD data line D4 //
#define D4              4
#endif
#ifndef D5                               // LCD data line D5 //
#define D5              5
#endif
#ifndef D6                               // LCD data line D6 //
#define D6              6
#endif
#ifndef D7                               // LCD data line D7 //
#define D7              7
#endif

#define CLEARDISPLAY   0X01
#define SETCURSOR      0X80

typedef uint8_t byte;
typedef int8_t sbyte;

// if macros.h is included from any other file this is not needed
// ?? maybe just include macros.h ??
#define BV(bit)               (1 << bit)
#define set_bit(sfr, bit)     (_SFR_BYTE(sfr) |= BV(bit))  // old sbi()
#define clear_bit(sfr, bit)   (_SFR_BYTE(sfr) &= ~BV(bit)) // old cbi()
#define toggle_bit(sfr, bit)  (_SFR_BYTE(sfr) ^= BV(bit))  


/**
* @name functions
*/

/**
 @brief initialize ports and approprieate pins for output
        for LCD data and LCD control ports
 @param   none
 @return   none
 @see      
*/
 void setupLCDPorts(void);


/**
 @brief  pulse enable line to "clock" data from LCD data port
          to LCD memory/display
 @param   none
 @return   none
 @see      
*/
void pulseEnable(void);


/**
 @brief  send 4-bits of data, mainly for LCD in 4-bit mode
         would have to add funcitonality for 8-bit mode
 @param   byte/nibble, 4-bits of data to be sent
 @return   none
 @see      
*/
void sendNibble(byte data);


/**
 @brief  send 8-bits of data to LCD, used for commands
         that cannot be sent in 4-bits in 4-bit mode
 @param byte, 8-bits of data to be sent
 @return   none
 @see      
*/
void sendByte(byte data);


/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_cmd(byte cmd);

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_char(byte ch);

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_init();

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_clear();

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_home();

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_goto(byte x, byte y);

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_line(byte row);

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_message(const char *text);

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_hex(int data);

/**
 @brief
 @param
 @return   none
 @see      
*/
void LCD_integer(int data);


#endif  // LCD_H