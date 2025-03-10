/*
 ============================================================================
 Name        : 05_decision_making_in_c.c
 Author      : OrS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
    int command = 5;

    // Using if-else
    if (command == 0) {
        printf("Starting system...\n");
    } else if (command == 1) {
        printf("Pausing system...\n");
    } else if (command == 2) {
        printf("Stopping system...\n");
    } else {
        printf("Invalid command.\n");
    }

    // Using switch
    switch (command) {
        case 0:
            printf("Starting system...\n");
            break;
        case 1:
            printf("Pausing system...\n");
            break;
        case 2:
            printf("Stopping system...\n");
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    return 0;
}
