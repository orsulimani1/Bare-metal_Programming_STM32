/*
 ============================================================================
 Name        : 04_storage_class_specifiers.c
 Author      : OrS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

// File-scope static variable (only accessible within file1.c)
static int staticCounter = 0;

// Externally visible function (can be called from other files)
void incrementCounter(void) {
    staticCounter++;
    printf("staticCounter in file1.c: %d\n", staticCounter);
}

// Another file-scope static function (private to file1.c)
static void debugMessage(void) {
	static int function_specific = 0;
	function_specific++;
    printf("Debug: staticCounter is currently %d\n", staticCounter);
    printf("Debug: function_specific is currently %d\n", function_specific);
}

void callDebug(void) {
    debugMessage(); // We can call this private static function within the same file
}
