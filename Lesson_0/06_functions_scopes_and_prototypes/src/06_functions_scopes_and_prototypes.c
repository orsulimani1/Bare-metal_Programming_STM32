/*
 ============================================================================
 Name        : 06_functions_scopes_and_prototypes.c
 Author      : OrS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

// Global variable (file scope) - accessible by any function below
int globalCounter = 0;

// Function prototype
int multiply(int x, int y);

int main(void) {
    int localVar = 5;
    globalCounter = 10;

    printf("Before multiply: globalCounter = %d\n", globalCounter);

    int result = multiply(localVar, globalCounter);
    printf("Result of multiply: %d\n", result);

    printf("After multiply: globalCounter = %d\n", globalCounter);

    return 0;
}

// Function definition
int multiply(int x, int y) {
    globalCounter++; // modifies the global variable
    return x * y;
}
