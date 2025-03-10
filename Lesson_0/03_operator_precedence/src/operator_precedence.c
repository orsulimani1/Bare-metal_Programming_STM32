/*
 ============================================================================
 Name        : operator_precedence.c
 Author      : OrS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
    int x = 2, y = 3, z = 4;

    // Without parentheses
    int result1 = x + y * z;
    // y * z is evaluated first (because * has higher precedence), then added to x
    // => 2 + 12 = 14

    // With parentheses
    int result2 = (x + y) * z;
    // (x + y) is evaluated first, then multiplied by z
    // => (2 + 3) * 4 = 5 * 4 = 20

    // More complex example
    int complexExp = x + y << 2 - z;
    // Precedence order (from high to low, simplified):
    // 1) - (unary or in expression if it's negative sign?),
    // 2) << (left shift),
    // 3) + (addition),
    // Actually for x + y << 2 - z:
    //   - is the same precedence as +, but left-to-right associativity can matter
    // Let's clarify by rewriting:
    //   int temp = (x + y); // 2 + 3 = 5
    //   temp << 2;         // 5 << 2 = 20
    //   20 - z             // 20 - 4 = 16
    // So complexExp = 16
    // But note: This can be tricky! It's safer to use parentheses if you want to be sure of the intended operations.

    printf("x + y * z = %d\n", result1);
    printf("(x + y) * z = %d\n", result2);
    printf("x + y << 2 - z = %d\n", complexExp);

    // Best practice: use parentheses for clarity
    int explicitExp = ( (x + y) << 2 ) - z;
    // => ( (5) << 2 ) - 4 = 20 - 4 = 16
    printf("((x + y) << 2) - z = %d (explicit)\n", explicitExp);

    return 0;
}
