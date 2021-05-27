#include "delay.h"

void delay_us(uint32_t delay)
{
    uint32_t i = 0;
    if (FREQ_24_MHZ)
    {
        for (i = 0; i < delay; i++)
        {
            __delay_cycles(0);
        }
    }
}
