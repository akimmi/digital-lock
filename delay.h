#ifndef DELAY_H
#define DELAY_H

#include "msp.h"
#define FREQ_1_MHZ CS_CTL0_DCORSEL_0
#define FREQ_3_MHZ CS_CTL0_DCORSEL_1
#define FREQ_6_MHZ CS_CTL0_DCORSEL_2
#define FREQ_12_MHZ CS_CTL0_DCORSEL_3
#define FREQ_24_MHZ CS_CTL0_DCORSEL_4

void delay_us(uint32_t delay);

#endif
