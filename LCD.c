#include "LCD.h"
#include "msp.h"

 // Function to initialize the LCD display
    // 8-bit mode, 2 line, cursor on
    void LCD_init(void) {
        // Setup GPIO for P3 and P4 to use LCD
        P3->SEL0 &= ~(RS | RW | EN);
        P3->SEL1 &= ~(RS | RW | EN);
        P2->SEL0 = 0x00;
        P2->SEL1 = 0x00;
        P3->DIR |= RS | RW | EN; // make P3 pins output for control
        P2->DIR = 0xFF;          // make P4 pins output for data
        P3->OUT &= ~EN;           // Set Enable low
        delay_us(50000);             // wait >40 ms for LCD to power up
        LCD_command(MODE_4_BIT | MODE_2_LINE);  // wake up initialization
        LCD_command(MODE_4_BIT | MODE_2_LINE);  // set 8-bit data, 2-line
        LCD_command(DISPLAY_ON | CURSOR_ON);    // display and cursor on
        LCD_command(CLR_DISP);                  // clear screen
        LCD_command(CURSOR_RIGHT);              // move cursor right after each char
    }
 // Function to send a single command to the LCD in 8-bit mode
        void LCD_command(unsigned char command) {
            P3->OUT &= ~(RS | RW);  // RS = 0, RW = 0
            P2->OUT = command;      // put command on data bus
            P3->OUT |= EN;          // Pulse E for > 460 ns
            delay_us(1);           
            P3->OUT &= ~EN;
            P2->OUT = command << 4;      // put second 4 bits of command on data bus
            P3->OUT |= EN;          // Pulse E for > 460 ns
            delay_us(1);
            P3->OUT &= ~EN;
            if (command < 4)
                delay_us(2000);         // command 1 and 2 need up to 1.52ms
            else
                delay_us(40);       // all others 37 us
        }
// Function to write a single character at the cursor location
        void LCD_write(unsigned char letter) {
            P3->OUT |= RS;           // RS = 1
            P3->OUT &= ~RW;          // R/W = 0
            P2->OUT = letter;       // put first 4 bits on data bus
            P3->OUT |= EN;
            delay_us(1);             // pulse E > 460 ns
            P3->OUT &= ~EN;
            P2->OUT = letter << 4;        // put second 4 bits on data bus
            P3->OUT |= EN;
            delay_us(1);             // pulse E > 460 ns
            P3->OUT &= ~EN;
            delay_us(2);             // wait for LCD to display
        }


