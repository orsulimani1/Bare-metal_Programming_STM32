/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include<stdio.h>
#include <stdint.h>

void change_access_level_unpriv(void)
{

	//read
	__asm volatile ("MRS R0,CONTROL");
	//modify
	__asm volatile ("ORR R0,R0,#0x01");
	//write
//	__asm volatile ("MSR CONTROL,R0");

}

int main(void)
{
	printf("In thread mode : before interrupt\n");


	change_access_level_unpriv();


	void (*fun_ptr)(void);

   /* storing some address in the function pointer variable */
	fun_ptr = change_access_level_unpriv;
//	fun_ptr = (void*)0x8000260;

  /* Here the address  gets copied into PC
   * 0th bit of the address will be copied into T bit.
   *Since the 0th bit is 0, T bit becomes 0 which raises processor fault */
	fun_ptr();

	printf("In thread mode : after interrupt\n");
	for(;;);
}

void HardFault_Handler(void)
{
	printf("Hard fault detected\n");
	while(1);
}
