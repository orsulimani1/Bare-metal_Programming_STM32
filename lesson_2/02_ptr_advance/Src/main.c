/*
 * main.c
 *
 *  Created on: Mar 24, 2025
 *      Author: Orr
 */

#include <stdint.h>
#include <stdio.h>

/********************* function pointers *******************/
typedef int (*Operation)(int, int);

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int calculate(int x, int y, Operation op) {
    return op(x, y); // Call the function through pointer
}
/********************* passing pointers to functions*******************/

//void modifyValue(int ***ppp) {
//    ***ppp = 100; // Modify through three levels of indirection
//}
//
//void passToModifier(int **pp) {
//    modifyValue(&pp); // Pass address of the pointer-to-pointer
//}

void modifyValue(int *ppp) {
    *ppp = 100; // Modify through three levels of indirection
}

void passToModifier(int *pp) {
    modifyValue(pp); // Pass address of the pointer-to-pointer
}

void updateVariable(int *p) {
    passToModifier(p); // Pass address of the pointer
}
/********************* end *******************/


int main(){
	// pointer to pointer
	int value = 42;
	int *ptr1 = &value;    // Points to value
	int **ptr2 = &ptr1;    // Points to ptr1

	**ptr2 = 100;          // Changes value through two levels
	printf("%d\n", value); // Prints 100

	//	passing pointers to functions
	int x = 5;
	updateVariable(&x); // Pass address of x
	printf("%d\n", x);  // Prints 100

	//	function pointers
    printf("%d\n", calculate(5, 3, add));      // Prints 8
    printf("%d\n", calculate(5, 3, multiply)); // Prints 15

}
