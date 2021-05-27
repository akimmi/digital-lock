#include "keypad.h"

//function to initialize/reset keypad: rows driven, columns read.
void keypad_init(void) {
    P4->SEL0 = 0x00;        //setup GPIO input for keypad
    P4->SEL1 = 0x00;
    P4->DIR &= ~(col1 | col2 | col3 | col4); //P4 for input columns
    P4->REN |= (col1 | col2 | col3 | col4); //set up REN for inputs
    P4->OUT &= ~(col1 | col2 | col3 | col4);

    P5->SEL0 = 0x00;        //setup GPIO output for keypad
    P5->SEL1 = 0x00;
    P5->DIR |= (row1 | row2 | row3 | row4);   
    P5->OUT |= (row1 | row2 | row3 | row4);    //P5 for output rows
}

//function to wait to detect input
uint8_t keypad_wait(void) {
    uint8_t num= 0;
    while(1) {
        P5->OUT |= (row1 | row2 | row3 | row4);   //turn outputs back on after a keypad_check
        if (P4->IN & col1) {        //column 1 is high
            num = keypad_check1();
            return num;
        }
        else if (P4->IN & col2) {   //column 2 is high
            num = keypad_check2();
            return num;
        } 
        else if (P4->IN & col3) {   //column 3 is high
            num = keypad_check3();
            return num;
        }
        else if (P4->IN & col4) {    //column 4 is high
            num = keypad_check4();
            return num;
        }
    }
    
}

//functions to find which key was pressed
uint8_t keypad_check1(void) {
    P5->OUT &= ~(row1 | row2 | row3 | row4);  //turn off rows
    P5->OUT |= (row1);           //turns row1 on for check  
    if (P4->IN & col1) {         //checking if 1 is pushed button
        LCD_write('1');          //prints 1 on the LCD
        while(P4->IN & col1);    //waits until button is not pushed
        return 1;
    }
    P5->OUT &= ~(row1);    //end of row 1 check
    //
    P5->OUT |= (row2);      //turns row 2 on for check 
    if (P4->IN & col1) {    //checking if 4 is pushed button
        LCD_write('4');     //prints 4 on the LCD
        while(P4->IN & col1);  //waits until button is not pushed
        return 4;
    }
    P5->OUT &= ~(row2);    //end of row 2 check
    //
    P5->OUT |= (row3);    //turns row 3 on for check
    if (P4->IN & col1) {   //checking if 7 is pushed button
        LCD_write('7');      //prints 7 on the LCD
        while(P4->IN & col1); //waits until button is not pushed
        return 7;
    }
    P5->OUT &= ~(row3);  //end of row 3 check
    //
    P5->OUT |= (row4);       //turns row 4 on for check
    if (P4->IN & col1) {     //checking if * is pushed button
        LCD_write('*');      //prints * on the LCD
        while(P4->IN & col1);  //waits until button is not pushed
        return 13;
    }
    P5->OUT &= ~(row4); //end of row 4 check
    return 113;
}

uint8_t keypad_check2(void) {
    P5->OUT &= ~(row1 | row2 | row3 | row4);
    P5->OUT |= (row1);
    if ((P4->IN & col2)) {
        LCD_write('2');         //prints 2 on the LCD
        while(P4->IN & col2);
        return 2;
    }
    P5->OUT &= ~(row1);
    //
    P5->OUT |= (row2);
    if ((P4->IN & col2)) {
        LCD_write('5');        //prints 5 on the LCD
        while(P4->IN & col2);
        return 5;
    }
    P5->OUT &= ~(row2);
    //
    P5->OUT |= (row3);
    if ((P4->IN & col2)) {
        LCD_write('8');          //prints 8 on the LCD
        while(P4->IN & col2);
        return 8;
    }
    P5->OUT &= ~(row3);
    //
    P5->OUT |= (row4);
    if ((P4->IN & col2)) {
        LCD_write('0');          //prints 0 on the LCD
        while(P4->IN & col2);
        return 0;
    }
    P5->OUT &= ~(row4);
}

uint8_t keypad_check3(void) {
    P5->OUT &= ~(row1 | row2 | row3 | row4);
    P5->OUT |= (row1);
    if ((P4->IN & col3)) {
        LCD_write('3');         //prints 3 on the LCD
        while(P4->IN & col3);
        return 3;
    }
    P5->OUT &= ~(row1);
    //
    P5->OUT |= (row2);
    if ((P4->IN & col3)) { 
        LCD_write('6');          //prints 6 on the LCD
        while(P4->IN & col3);
        return 6;
    }
    P5->OUT &= ~(row2);
    //
    P5->OUT |= (row3);
    if ((P4->IN & col3)) {
        LCD_write('9');          //prints 9 on the LCD
        while(P4->IN & col3);
        return 9;
    }
    P5->OUT &= ~(row3);
    //
    P5->OUT |= (row4);
    if ((P4->IN & col3)) {
        LCD_write('#');          //prints # on the LCD
        while(P4->IN & col3);
        return 113;
    }
    P5->OUT &= ~(row4);
}

uint8_t keypad_check4(void) {
    P5->OUT &= ~(row1 | row2 | row3 | row4);
    P5->OUT |= (row1);
    if ((P4->IN & col4)) {
        LCD_write('A');          //prints A on the LCD
        while(P4->IN & col4);
        return 113;
    }
    P5->OUT &= ~(row1);
    //
    P5->OUT |= (row2);
    if ((P4->IN & col4)) {
        LCD_write('B');          //prints B on the LCD
        while(P4->IN & col4);
        return 113;
    }
    P5->OUT &= ~(row2);
    //
    P5->OUT |= (row3);
    if ((P4->IN & col4)) {
        LCD_write('C');          //prints C on the LCD
        while(P4->IN & col4);
        return 113;
    }
    P5->OUT &= ~(row3);
    //
    P5->OUT |= (row4);
    if ((P4->IN & col4)) {
        LCD_write('D');           //prints D on the LCD
        while(P4->IN & col4);
        return 113;
    }
    P5->OUT &= ~(row4);
}

