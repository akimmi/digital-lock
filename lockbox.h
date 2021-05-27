#ifndef LOCKBOX_H
#define LOCKBOX_H
#include "msp.h"
#include "delay.h"
#define KEY 0001001000110100

void lockbox_init(void);
void store_answer(uint8_t num[4]);
void check_answer(uint8_t num[4]);
void correct_answer(void);
void wrong_answer(void);

#endif
