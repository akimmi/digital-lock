#ifndef LCD_H
#define LCD_H
#include "msp.h"
#include "delay.h"

#define RS BIT5     /* P3.5 mask */
#define RW BIT6     /* P3.6 mask */
#define EN BIT7     /* P3.7 mask */// Define common LCD command functions
#define CLR_DISP      0x01    // Clear display
#define HOME          0x02    // Send cursor to home position
#define MODE_8_BIT    0x30    // LCD Mode options
#define MODE_4_BIT    0x20    //LCD 4 bit operations
#define MODE_2_LINE   0x28
#define CURSOR_ON     0x0A
#define CURSOR_BLINK  0x09
#define DISPLAY_ON    0x0C
#define CURSOR_RIGHT  0x06    // Cursor moves to right
#define CURSOR_LEFT   0x04    // Cursor moves to left
#define SET_CURSOR    0x80    // Set cursor position to SET_CURSOR | ADDRESSvoid LCD_init(void)

void LCD_init(void);
void LCD_command(unsigned char command);
void LCD_write(unsigned char letter);

#endif


