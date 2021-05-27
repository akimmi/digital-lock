#include "msp.h"
#include "keypad.h"
#include "LCD.h"
#include "delay.h"
#include "lockbox.h"

/**
 * main.c
 */
void main(void)
{
    while(1){
    uint8_t num[4];
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	LCD_init();
	lockbox_init();
	keypad_init();
	store_answer(num);
// 	uint8_t A= num[0];
// 	uint8_t B= num[1];
// 	uint8_t C= num[2];
// 	uint8_t D= num[3];
	check_answer(num);
    }
}
