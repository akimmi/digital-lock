#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "msp.h"
#include "delay.h"
#include "LCD.h"

#define col4 BIT0     //P4.0
#define col3 BIT1     //P4.1
#define col2 BIT2     //P4.2
#define col1 BIT3     //P4.3
#define row4 BIT4     //P5.4
#define row3 BIT5     //P5.5
#define row2 BIT6     //P5.6
#define row1 BIT7     //P5.7


void keypad_init(void);
uint8_t keypad_wait(void);
uint8_t keypad_check1(void);
uint8_t keypad_check2(void);
uint8_t keypad_check3(void);
uint8_t keypad_check4(void);

#endif /* KEYPAD_H_ */


