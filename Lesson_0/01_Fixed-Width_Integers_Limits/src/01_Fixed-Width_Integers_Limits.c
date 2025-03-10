/*
 ============================================================================
 Name        : 01_Fixed-Width_Integers_Limits.c
 Author      : OrS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
    int8_t Int_8_bit = INT8_MAX;      // 127
    uint16_t UInt_16_bit = UINT16_MAX; // 65535
    int32_t Int_32_bit = INT32_MIN;	  // (-2147483647 - 1)
    uint64_t UInt_64_bit = UINT64_MAX; // 0xffffffffffffffffULL /* 18446744073709551615ULL */

    printf("Int_8_bit = %d (INT8_MAX = %d)\n", Int_8_bit, INT8_MAX);
    printf("UInt_16_bit = %u (UINT16_MAX = %u)\n", UInt_16_bit, UINT16_MAX);
    printf("Int_32_bit = %d (INT32_MIN = %d)\n", Int_32_bit, INT32_MIN);
    printf("UInt_64_bit = %llu (UINT64_MAX = %llu)\n", UInt_64_bit, UINT64_MAX);
    return 0;
}
