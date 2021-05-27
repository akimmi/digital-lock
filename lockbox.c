#include "lockbox.h" //made for this project
#include "LCD.h"    //from A3
#include "keypad.h" //from A4
#include "delay.h"
#include <stdio.h>
#include <string.h>

void lockbox_init(void){                             //printing "LOCKED ENTER KEY"
    LCD_write('L');    
    LCD_write('o');    
    LCD_write('c');    
    LCD_write('k');    
    LCD_write('e');  
    LCD_write('d');
    LCD_command(SET_CURSOR | 0x40);                  // Move cursor to 2nd line   
    LCD_write('E');    
    LCD_write('n');    
    LCD_write('t');    
    LCD_write('e');    
    LCD_write('r');    
    LCD_command(SET_CURSOR | 0x46);                  //add space 
    LCD_write('K');
    LCD_write('e');
    LCD_write('y');
    LCD_command(SET_CURSOR | 0x4A);
    }
    
//struct __attribute__((__packed__)) key{
//    uint8_t* first;                          //pointer for first digit
//     uint8_t* sec;                            //pointer for second digit
//     uint8_t* third;                          //pointer for third digit
//     uint8_t* fouth;                          //pointer for fourth digit
// }

void store_answer(uint8_t num[4]){
    uint8_t dig = 0;                             //placeholder to store last digit
    int i = 0;                                   //num counter number
    for(i=0; i<4; i++){                          //counter to get only 4 digit input 
        dig = keypad_wait();                     //get user pin attempt
        num[i] = dig;                            //store last inputted value into final number                           
         if (dig == 13){
            LCD_command(CLR_DISP);               //clear display
            delay_us(200000);
            lockbox_init();                     //go back to beginning
            num[0] = 0;                         //clear stored answer
            num[1] = 0;                         //clear stored answer
            num[2] = 0;                         //clear stored answer
            num[3] = 0;                         //clear stored answer
        }
    }
}

void check_answer(uint8_t num[4]){
    uint8_t i = 0;                                  //num counter number
    uint8_t wrong = 0;
    uint8_t* answer = "1234";
    uint8_t A= answer[0];
	uint8_t B= answer[1];
	uint8_t C= answer[2];
	uint8_t D= answer[3];
    for (i=0; i<4; i++){
        if ((uint8_t)answer[i] != (num[i]+48)){
            wrong = 1;                               //found a wrong answer
        }
    }
    if (wrong == 0){                                 //attempt is hundo % correct
        correct_answer(); 
    }
    else{                                            //oh boy, you didnt get the pin right
        wrong_answer();   
    }
}

void correct_answer(void){
    LCD_command(CLR_DISP);
    LCD_write('U');
    LCD_write('n');
    LCD_write('l');    
    LCD_write('o');    
    LCD_write('c');    
    LCD_write('k');    
    LCD_write('e');  
    LCD_write('d');
    delay_us(200000);                                 //wait 2 secs to show unlocked
    LCD_command(CLR_DISP);                          //clear display
    lockbox_init();                                //restart program
}

void wrong_answer(void){
    LCD_command(CLR_DISP);                         //clear display
    lockbox_init();                                //restart program
} 