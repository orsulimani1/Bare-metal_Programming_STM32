/*
 * stm32f411.h
 *
 *  Created on: Apr 5, 2025
 *      Author: Orr
 */

#ifndef STM32F411_H_
#define STM32F411_H_

#define GPIOA_BASE_ADDR   (0x40020000)
#define GPIOB_BASE_ADDR   (0x40020C00)
#define GPIOC_BASE_ADDR   (0x40020C00)
#define GPIOD_BASE_ADDR   (0x40020C00)
#define GPIOE_BASE_ADDR   (0x40020C00)
#define GPIOH_BASE_ADDR   (0x40020C00)
#define RCC_BASE_ADDR 	  (0x40023800)



/*************************Bit-fields************************/

typedef struct {
    volatile uint32_t MODER0 : 2;
    volatile uint32_t MODER1 : 2;
    volatile uint32_t MODER2 : 2;
    volatile uint32_t MODER3 : 2;
    volatile uint32_t MODER4 : 2;
    volatile uint32_t MODER5 : 2;
    volatile uint32_t MODER6 : 2;
    volatile uint32_t MODER7 : 2;
    volatile uint32_t MODER8 : 2;
    volatile uint32_t MODER9 : 2;
    volatile uint32_t MODER10 : 2;
    volatile uint32_t MODER11 : 2;
    volatile uint32_t MODER12 : 2;
    volatile uint32_t MODER13 : 2;
    volatile uint32_t MODER14 : 2;
    volatile uint32_t MODER15 : 2;
} GPIO_MODER_BitField;

// Bitfield structure for OTYPER (Output type register)
typedef struct {
    volatile uint32_t OT0 : 1;       // Pin 0 output type
    volatile uint32_t OT1 : 1;       // Pin 1 output type
    volatile uint32_t OT2 : 1;       // Pin 2 output type
    volatile uint32_t OT3 : 1;       // Pin 3 output type
    volatile uint32_t OT4 : 1;       // Pin 4 output type
    volatile uint32_t OT5 : 1;       // Pin 5 output type
    volatile uint32_t OT6 : 1;       // Pin 6 output type
    volatile uint32_t OT7 : 1;       // Pin 7 output type
    volatile uint32_t OT8 : 1;       // Pin 8 output type
    volatile uint32_t OT9 : 1;       // Pin 9 output type
    volatile uint32_t OT10 : 1;      // Pin 10 output type
    volatile uint32_t OT11 : 1;      // Pin 11 output type
    volatile uint32_t OT12 : 1;      // Pin 12 output type
    volatile uint32_t OT13 : 1;      // Pin 13 output type
    volatile uint32_t OT14 : 1;      // Pin 14 output type
    volatile uint32_t OT15 : 1;      // Pin 15 output type
    volatile uint32_t RESERVED : 16; // Reserved bits 16-31
} GPIO_OTYPER_BitField;

// Bitfield structure for OSPEEDR (Output speed register)
typedef struct {
    volatile uint32_t OSPEEDR0 : 2;  // Pin 0 output speed
    volatile uint32_t OSPEEDR1 : 2;  // Pin 1 output speed
    volatile uint32_t OSPEEDR2 : 2;  // Pin 2 output speed
    volatile uint32_t OSPEEDR3 : 2;  // Pin 3 output speed
    volatile uint32_t OSPEEDR4 : 2;  // Pin 4 output speed
    volatile uint32_t OSPEEDR5 : 2;  // Pin 5 output speed
    volatile uint32_t OSPEEDR6 : 2;  // Pin 6 output speed
    volatile uint32_t OSPEEDR7 : 2;  // Pin 7 output speed
    volatile uint32_t OSPEEDR8 : 2;  // Pin 8 output speed
    volatile uint32_t OSPEEDR9 : 2;  // Pin 9 output speed
    volatile uint32_t OSPEEDR10 : 2; // Pin 10 output speed
    volatile uint32_t OSPEEDR11 : 2; // Pin 11 output speed
    volatile uint32_t OSPEEDR12 : 2; // Pin 12 output speed
    volatile uint32_t OSPEEDR13 : 2; // Pin 13 output speed
    volatile uint32_t OSPEEDR14 : 2; // Pin 14 output speed
    volatile uint32_t OSPEEDR15 : 2; // Pin 15 output speed
} GPIO_OSPEEDR_BitField;

// Bitfield structure for PUPDR (Pull-up/pull-down register)
typedef struct {
    volatile uint32_t PUPDR0 : 2;    // Pin 0 pull-up/pull-down
    volatile uint32_t PUPDR1 : 2;    // Pin 1 pull-up/pull-down
    volatile uint32_t PUPDR2 : 2;    // Pin 2 pull-up/pull-down
    volatile uint32_t PUPDR3 : 2;    // Pin 3 pull-up/pull-down
    volatile uint32_t PUPDR4 : 2;    // Pin 4 pull-up/pull-down
    volatile uint32_t PUPDR5 : 2;    // Pin 5 pull-up/pull-down
    volatile uint32_t PUPDR6 : 2;    // Pin 6 pull-up/pull-down
    volatile uint32_t PUPDR7 : 2;    // Pin 7 pull-up/pull-down
    volatile uint32_t PUPDR8 : 2;    // Pin 8 pull-up/pull-down
    volatile uint32_t PUPDR9 : 2;    // Pin 9 pull-up/pull-down
    volatile uint32_t PUPDR10 : 2;   // Pin 10 pull-up/pull-down
    volatile uint32_t PUPDR11 : 2;   // Pin 11 pull-up/pull-down
    volatile uint32_t PUPDR12 : 2;   // Pin 12 pull-up/pull-down
    volatile uint32_t PUPDR13 : 2;   // Pin 13 pull-up/pull-down
    volatile uint32_t PUPDR14 : 2;   // Pin 14 pull-up/pull-down
    volatile uint32_t PUPDR15 : 2;   // Pin 15 pull-up/pull-down
} GPIO_PUPDR_BitField;

// Bitfield structure for IDR (Input data register)
typedef struct {
    volatile uint32_t IDR0 : 1;      // Pin 0 input data
    volatile uint32_t IDR1 : 1;      // Pin 1 input data
    volatile uint32_t IDR2 : 1;      // Pin 2 input data
    volatile uint32_t IDR3 : 1;      // Pin 3 input data
    volatile uint32_t IDR4 : 1;      // Pin 4 input data
    volatile uint32_t IDR5 : 1;      // Pin 5 input data
    volatile uint32_t IDR6 : 1;      // Pin 6 input data
    volatile uint32_t IDR7 : 1;      // Pin 7 input data
    volatile uint32_t IDR8 : 1;      // Pin 8 input data
    volatile uint32_t IDR9 : 1;      // Pin 9 input data
    volatile uint32_t IDR10 : 1;     // Pin 10 input data
    volatile uint32_t IDR11 : 1;     // Pin 11 input data
    volatile uint32_t IDR12 : 1;     // Pin 12 input data
    volatile uint32_t IDR13 : 1;     // Pin 13 input data
    volatile uint32_t IDR14 : 1;     // Pin 14 input data
    volatile uint32_t IDR15 : 1;     // Pin 15 input data
    volatile uint32_t RESERVED : 16; // Reserved bits 16-31
} GPIO_IDR_BitField;

// Bitfield structure for ODR (Output data register)
typedef struct {
    volatile uint32_t ODR0 : 1;      // Pin 0 output data
    volatile uint32_t ODR1 : 1;      // Pin 1 output data
    volatile uint32_t ODR2 : 1;      // Pin 2 output data
    volatile uint32_t ODR3 : 1;      // Pin 3 output data
    volatile uint32_t ODR4 : 1;      // Pin 4 output data
    volatile uint32_t ODR5 : 1;      // Pin 5 output data
    volatile uint32_t ODR6 : 1;      // Pin 6 output data
    volatile uint32_t ODR7 : 1;      // Pin 7 output data
    volatile uint32_t ODR8 : 1;      // Pin 8 output data
    volatile uint32_t ODR9 : 1;      // Pin 9 output data
    volatile uint32_t ODR10 : 1;     // Pin 10 output data
    volatile uint32_t ODR11 : 1;     // Pin 11 output data
    volatile uint32_t ODR12 : 1;     // Pin 12 output data
    volatile uint32_t ODR13 : 1;     // Pin 13 output data
    volatile uint32_t ODR14 : 1;     // Pin 14 output data
    volatile uint32_t ODR15 : 1;     // Pin 15 output data
    volatile uint32_t RESERVED : 16; // Reserved bits 16-31
} GPIO_ODR_BitField;

// Bitfield structure for BSRR (Bit set/reset register)
typedef struct {
    volatile uint32_t BS0 : 1;       // Pin 0 set bit
    volatile uint32_t BS1 : 1;       // Pin 1 set bit
    volatile uint32_t BS2 : 1;       // Pin 2 set bit
    volatile uint32_t BS3 : 1;       // Pin 3 set bit
    volatile uint32_t BS4 : 1;       // Pin 4 set bit
    volatile uint32_t BS5 : 1;       // Pin 5 set bit
    volatile uint32_t BS6 : 1;       // Pin 6 set bit
    volatile uint32_t BS7 : 1;       // Pin 7 set bit
    volatile uint32_t BS8 : 1;       // Pin 8 set bit
    volatile uint32_t BS9 : 1;       // Pin 9 set bit
    volatile uint32_t BS10 : 1;      // Pin 10 set bit
    volatile uint32_t BS11 : 1;      // Pin 11 set bit
    volatile uint32_t BS12 : 1;      // Pin 12 set bit
    volatile uint32_t BS13 : 1;      // Pin 13 set bit
    volatile uint32_t BS14 : 1;      // Pin 14 set bit
    volatile uint32_t BS15 : 1;      // Pin 15 set bit
    volatile uint32_t BR0 : 1;       // Pin 0 reset bit
    volatile uint32_t BR1 : 1;       // Pin 1 reset bit
    volatile uint32_t BR2 : 1;       // Pin 2 reset bit
    volatile uint32_t BR3 : 1;       // Pin 3 reset bit
    volatile uint32_t BR4 : 1;       // Pin 4 reset bit
    volatile uint32_t BR5 : 1;       // Pin 5 reset bit
    volatile uint32_t BR6 : 1;       // Pin 6 reset bit
    volatile uint32_t BR7 : 1;       // Pin 7 reset bit
    volatile uint32_t BR8 : 1;       // Pin 8 reset bit
    volatile uint32_t BR9 : 1;       // Pin 9 reset bit
    volatile uint32_t BR10 : 1;      // Pin 10 reset bit
    volatile uint32_t BR11 : 1;      // Pin 11 reset bit
    volatile uint32_t BR12 : 1;      // Pin 12 reset bit
    volatile uint32_t BR13 : 1;      // Pin 13 reset bit
    volatile uint32_t BR14 : 1;      // Pin 14 reset bit
    volatile uint32_t BR15 : 1;      // Pin 15 reset bit
} GPIO_BSRR_BitField;

// Bitfield structure for LCKR (Lock register)
typedef struct {
    volatile uint32_t LCK0 : 1;      // Pin 0 lock bit
    volatile uint32_t LCK1 : 1;      // Pin 1 lock bit
    volatile uint32_t LCK2 : 1;      // Pin 2 lock bit
    volatile uint32_t LCK3 : 1;      // Pin 3 lock bit
    volatile uint32_t LCK4 : 1;      // Pin 4 lock bit
    volatile uint32_t LCK5 : 1;      // Pin 5 lock bit
    volatile uint32_t LCK6 : 1;      // Pin 6 lock bit
    volatile uint32_t LCK7 : 1;      // Pin 7 lock bit
    volatile uint32_t LCK8 : 1;      // Pin 8 lock bit
    volatile uint32_t LCK9 : 1;      // Pin 9 lock bit
    volatile uint32_t LCK10 : 1;     // Pin 10 lock bit
    volatile uint32_t LCK11 : 1;     // Pin 11 lock bit
    volatile uint32_t LCK12 : 1;     // Pin 12 lock bit
    volatile uint32_t LCK13 : 1;     // Pin 13 lock bit
    volatile uint32_t LCK14 : 1;     // Pin 14 lock bit
    volatile uint32_t LCK15 : 1;     // Pin 15 lock bit
    volatile uint32_t LCKK : 1;      // Lock key
    volatile uint32_t RESERVED : 15; // Reserved bits 17-31
} GPIO_LCKR_BitField;

// Bitfield structure for AFRL (Alternate function register)
typedef struct {
    volatile uint32_t AFRL0 : 4;     // Pin 0 alternate function
    volatile uint32_t AFRL1 : 4;     // Pin 1 alternate function
    volatile uint32_t AFRL2 : 4;     // Pin 2 alternate function
    volatile uint32_t AFRL3 : 4;     // Pin 3 alternate function
    volatile uint32_t AFRL4 : 4;     // Pin 4 alternate function
    volatile uint32_t AFRL5 : 4;     // Pin 5 alternate function
    volatile uint32_t AFRL6 : 4;     // Pin 6 alternate function
    volatile uint32_t AFRL7 : 4;     // Pin 7 alternate function
} GPIO_AFR_BitField;

typedef struct {
    volatile GPIO_MODER_BitField  MODER;    // Offset: 0x00
    volatile GPIO_OTYPER_BitField OTYPER;   // Offset: 0x04
    volatile GPIO_OSPEEDR_BitField OSPEEDR;  // Offset: 0x08
    volatile GPIO_PUPDR_BitField PUPDR;    // Offset: 0x0C
    volatile GPIO_IDR_BitField IDR;      // Offset: 0x10
    volatile GPIO_ODR_BitField ODR;      // Offset: 0x14
    volatile GPIO_BSRR_BitField BSRR;     // Offset: 0x18
    volatile GPIO_LCKR_BitField LCKR;     // Offset: 0x1C
    volatile GPIO_AFR_BitField AFR[2];   // Offset: 0x20-0x24
} GPIO_TypeDef;

typedef struct {
} RCC_TypeDef;

const uint32_t RCC_AHB1ENR      = ((0x40023800) + (0x30));
const uint32_t GPIOD_MODER      = (GPIOD_BASE_ADDR + (0x0));
const uint32_t GPIOD_ODR        = (GPIOD_BASE_ADDR + (0x14));
const uint32_t GPIO_OUTPUT_MODE = 0x1;


#endif /* STM32F411_H_ */
