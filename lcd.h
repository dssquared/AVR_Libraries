/**************************************************************
****        header file/AVR library for 44780 LCD          ****
****  uses 4-bit mode of LCD, set ports/pins accordinglly  ****
**** this example uses PortD of AVR for 4-bit LCD data bus ****
****           and PortB for the LCD control pins,         ****
****    assumed LCD R/W is pulled low (only writting)      ****
****    author: David Schwehr 2015                         ****
**************************************************************/

#ifndef LCD_H
#define LCD_H

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


// if macros.h is included from any other file this is not needed
// but use #ifndef to be safe here and just confirms macros are linked
//    ?? maybe use ifndef to check and include macros ????
#ifndef BV()
#define BV(bit)               (1 << bit)
#endif
#ifndef set_bit()
#define set_bit(sfr, bit)     (_SFR_BYTE(sfr) |= BV(bit))  // old sbi()
#endif
#ifndef clear_bit()
#define clear_bit(sfr, bit)   (_SFR_BYTE(sfr) &= ~BV(bit)) // old cbi()
#endif
#ifndef toggle_bit()
#define toggle_bit(sfr, bit)  (_SFR_BYTE(sfr) ^= BV(bit))  
#endif

void pulseEnable(void);
void sendNibble(byte data);
void sendByte(byte data);
void LCD_cmd(byte cmd);


#endif  // LCD_H