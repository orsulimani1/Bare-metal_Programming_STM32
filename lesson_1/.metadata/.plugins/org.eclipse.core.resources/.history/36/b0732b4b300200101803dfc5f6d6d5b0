/*
 * itm_debug.c
 *
 *  Created on: Mar 15, 2025
 *      Author: admin
 */


#include <stdint.h>

/* Debug Exception and Monitor Control Register (DEMCR) */
#define DEMCR                  *((volatile uint32_t*) 0xE000EDFCU )
/* ITM Stimulus Port 0 */
#define ITM_STIMULUS_PORT0     *((volatile uint32_t*) 0xE0000000 )
/* ITM Trace Enable Register */
#define ITM_TRACE_EN           *((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint8_t ch)
{
    // Enable TRCENA (Trace Enable)
    DEMCR |= (1 << 24);

    // Enable stimulus port 0
    ITM_TRACE_EN |= (1 << 0);

    // Wait until FIFO is ready in bit [0]
    while (!(ITM_STIMULUS_PORT0 & 1));

    // Write to ITM stimulus port 0
    ITM_STIMULUS_PORT0 = ch;
}
