/*
 * file_2.c
 *
 *  Created on: Mar 8, 2025
 *      Author: admin
 */


#include <stdio.h>

// Function prototypes declared as extern (they exist in file1.c)
extern void incrementCounter(void);
extern void callDebug(void);

int main(void) {
    incrementCounter(); // increments staticCounter in file1.c
    incrementCounter(); // increments again

    callDebug(); // calls the private debugMessage() in file1.c
    callDebug();
    callDebug();
    return 0;
}
