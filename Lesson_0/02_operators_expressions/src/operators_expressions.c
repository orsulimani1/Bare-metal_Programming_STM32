/*
 ============================================================================
 Name        : operators_expressions.c
 Author      : OrS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t a = 0b10101010; // 170 in decimal
    uint8_t b = 0b11001100; // 204 in decimal

    // Arithmetic
    int sum = a + b;
    int difference = a - b;

    // Bitwise
    uint8_t bitwiseAnd = a & b; // 10001000 (decimal 136)
    uint8_t bitwiseOr  = a | b; // 11101110 (decimal 238)
    uint8_t bitwiseXor = a ^ b; // 01100110 (decimal 102)
    uint8_t bitwiseNot = ~a;    // 01010101 (decimal 85)

    // Shift operations
    uint8_t shiftedLeft = a << 1;  // 01010100 (decimal 84)
    uint8_t shiftedRight = b >> 2; // 00110011 (decimal 51)

    printf("Arithmetic:\n");
    printf("  a + b = %d\n", sum);
    printf("  a - b = %d\n", difference);

    printf("\nBitwise:\n");
    printf("  a & b = 0x%02X\n", bitwiseAnd);
    printf("  a | b = 0x%02X\n", bitwiseOr);
    printf("  a ^ b = 0x%02X\n", bitwiseXor);
    printf("  ~a    = 0x%02X\n", bitwiseNot);

    printf("\nShifts:\n");
    printf("  a << 1 = 0x%02X\n", shiftedLeft);
    printf("  b >> 2 = 0x%02X\n", shiftedRight);

    // Logical operators
    // Checking if a is nonzero AND b is greater than 200
    if((a != 0) && (b > 200)) {
        printf("\nLogical AND condition met.\n");
    } else {
        printf("\nLogical AND condition not met.\n");
    }

    return 0;
}
