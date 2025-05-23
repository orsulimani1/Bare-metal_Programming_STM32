/*
 * main.c
 *
 *  Created on: Mar 16, 2025
 *      Author: admin
 */


#include <stdio.h>
#include <stdint.h>

#define BIT_3  (3 << 3)
#define BIT_5  (1 << 5)

int main(void)
{
    uint8_t reg = 0x1; // Example 8-bit register
    printf("before setting bit 3: 0x%02X\n", reg); // Expect 0x08

    // Set bit 3
    reg |= BIT_3;
    printf("After setting bit 3: 0x%02X\n", reg); // Expect 0x08

    // Clear bit 3
    reg &= ~BIT_3;
    printf("After clearing bit 3: 0x%02X\n", reg); // Expect 0x00

    // Toggle bit 5
    reg ^= BIT_5;
    printf("After toggling bit 5: 0x%02X\n", reg); // Expect 0x20

    // Toggle bit 5 again
    reg ^= BIT_5;
    printf("After toggling bit 5 again: 0x%02X\n", reg); // Expect 0x00

    return 0;
}






