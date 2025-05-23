/*
 * main.c
 *
 *  Created on: Mar 16, 2025
 *      Author: admin
 */


#include <stdint.h>
#include <stdio.h>

typedef struct ControlReg_ {
    uint32_t mode     : 3;  // 3 bits for mode
    uint32_t enabled  : 1;  // 1 bit for enable
    uint32_t reserved : 4;  // 4 bits reserved
    uint32_t counter  : 8;  // 8 bits for a counter
    uint32_t unused   : 16; // remainder 16 bits
} ControlReg_t;

typedef union DataConverter_ {
	ControlReg_t bitfield_data;
    uint64_t unsigned_data;
}__attribute__((packed)) DataConverter_t;

int main(void) {
	DataConverter_t reg;

    // Set the mode to 5 (binary 101)
	reg.bitfield_data.mode = 5;
    // Enable the bit
	reg.bitfield_data.enabled = 1;
    // Set counter to 0x3A
	reg.bitfield_data.counter = 0x3A;

    printf("reg = 0x%08X\n", *((uint32_t*)&reg.bitfield_data));
    printf("reg = 0x%08X\n", reg.unsigned_data);

    // This prints the entire 32-bit value
    return 0;
}
