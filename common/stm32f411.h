/*
 * stm32f411.h
 *
 *  Created on: Apr 5, 2025
 *      Author: Orr
 */

#ifndef STM32F411_H_
#define STM32F411_H_

#include <stdint.h>


#define GPIOA_BASE_ADDR   (0x40020000)
#define GPIOB_BASE_ADDR   (0x40020400)
#define GPIOC_BASE_ADDR   (0x40020800)
#define GPIOD_BASE_ADDR   (0x40020C00)
#define GPIOE_BASE_ADDR   (0x40021000)
#define GPIOH_BASE_ADDR   (0x40021C00)
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

const uint32_t RCC_AHB1ENR      = ((RCC_BASE_ADDR) + (0x30));
const uint32_t GPIOD_MODER      = (GPIOD_BASE_ADDR + (0x0));
const uint32_t GPIOD_ODR        = (GPIOD_BASE_ADDR + (0x14));
const uint32_t GPIO_OUTPUT_MODE = 0x1;

/* Core Registers */
#define SCB_BASE            0xE000ED00UL
#define NVIC_BASE           0xE000E100UL
#define SYSTICK_BASE        0xE000E010UL
#define STIR_BASE           0xE000EF00UL

/* SCB Registers */
#define SCB_CPUID           (*(volatile uint32_t *)(SCB_BASE + 0x00UL))
#define SCB_ICSR            (*(volatile uint32_t *)(SCB_BASE + 0x04UL))
#define SCB_VTOR            (*(volatile uint32_t *)(SCB_BASE + 0x08UL))
#define SCB_AIRCR           (*(volatile uint32_t *)(SCB_BASE + 0x0CUL))
#define SCB_SCR             (*(volatile uint32_t *)(SCB_BASE + 0x10UL))
#define SCB_CCR             (*(volatile uint32_t *)(SCB_BASE + 0x14UL))
#define SCB_SHPR1           (*(volatile uint32_t *)(SCB_BASE + 0x18UL))
#define SCB_SHPR2           (*(volatile uint32_t *)(SCB_BASE + 0x1CUL))
#define SCB_SHPR3           (*(volatile uint32_t *)(SCB_BASE + 0x20UL))
#define SCB_SHCSR           (*(volatile uint32_t *)(SCB_BASE + 0x24UL))
#define SCB_CFSR            (*(volatile uint32_t *)(SCB_BASE + 0x28UL))
#define SCB_HFSR            (*(volatile uint32_t *)(SCB_BASE + 0x2CUL))
#define SCB_DFSR            (*(volatile uint32_t *)(SCB_BASE + 0x30UL))
#define SCB_MMFAR           (*(volatile uint32_t *)(SCB_BASE + 0x34UL))
#define SCB_BFAR            (*(volatile uint32_t *)(SCB_BASE + 0x38UL))
#define SCB_AFSR            (*(volatile uint32_t *)(SCB_BASE + 0x3CUL))

/* NVIC Registers */
#define NVIC_ISER0          (*(volatile uint32_t *)(NVIC_BASE + 0x000UL))
#define NVIC_ISER1          (*(volatile uint32_t *)(NVIC_BASE + 0x004UL))
#define NVIC_ICER0          (*(volatile uint32_t *)(NVIC_BASE + 0x080UL))
#define NVIC_ICER1          (*(volatile uint32_t *)(NVIC_BASE + 0x084UL))
#define NVIC_ISPR0          (*(volatile uint32_t *)(NVIC_BASE + 0x100UL))
#define NVIC_ISPR1          (*(volatile uint32_t *)(NVIC_BASE + 0x104UL))
#define NVIC_ICPR0          (*(volatile uint32_t *)(NVIC_BASE + 0x180UL))
#define NVIC_ICPR1          (*(volatile uint32_t *)(NVIC_BASE + 0x184UL))
#define NVIC_IABR0          (*(volatile uint32_t *)(NVIC_BASE + 0x200UL))
#define NVIC_IABR1          (*(volatile uint32_t *)(NVIC_BASE + 0x204UL))
#define NVIC_IPR0           (*(volatile uint32_t *)(NVIC_BASE + 0x300UL))
#define NVIC_IPR1           (*(volatile uint32_t *)(NVIC_BASE + 0x304UL))
/* ... more priority registers as needed */

/* Software Trigger Interrupt Register */
#define NVIC_STIR           (*(volatile uint32_t *)(STIR_BASE + 0x00UL))

/* SysTick Registers */
#define SYSTICK_CTRL        (*(volatile uint32_t *)(SYSTICK_BASE + 0x00UL))
#define SYSTICK_LOAD        (*(volatile uint32_t *)(SYSTICK_BASE + 0x04UL))
#define SYSTICK_VAL         (*(volatile uint32_t *)(SYSTICK_BASE + 0x08UL))
#define SYSTICK_CALIB       (*(volatile uint32_t *)(SYSTICK_BASE + 0x0CUL))

/* Memory Map */
#define FLASH_BASE          0x08000000UL
#define SRAM_BASE           0x20000000UL
#define PERIPH_BASE         0x40000000UL

/* SRAM Size (128KB for STM32F411VET6) */
#define SRAM_SIZE           0x20000UL

/* SHCSR bit definitions */
#define SCB_SHCSR_MEMFAULTENA_Pos     16
#define SCB_SHCSR_BUSFAULTENA_Pos     17
#define SCB_SHCSR_USGFAULTENA_Pos     18
#define SCB_SHCSR_MEMFAULTENA_Msk     (1UL << SCB_SHCSR_MEMFAULTENA_Pos)
#define SCB_SHCSR_BUSFAULTENA_Msk     (1UL << SCB_SHCSR_BUSFAULTENA_Pos)
#define SCB_SHCSR_USGFAULTENA_Msk     (1UL << SCB_SHCSR_USGFAULTENA_Pos)

/* AIRCR key for register writes */
#define SCB_AIRCR_VECTKEY_Pos         16
#define SCB_AIRCR_VECTKEY             (0x5FAUL << SCB_AIRCR_VECTKEY_Pos)
#define SCB_AIRCR_PRIGROUP_Pos        8
#define SCB_AIRCR_PRIGROUP_Msk        (7UL << SCB_AIRCR_PRIGROUP_Pos)

/* NVIC IRQ numbers for STM32F411VET6 */
typedef enum {
    NonMaskableInt_IRQn     = -14,
    HardFault_IRQn          = -13,
    MemoryManagement_IRQn   = -12,
    BusFault_IRQn           = -11,
    UsageFault_IRQn         = -10,
    SVCall_IRQn             = -5,
    DebugMonitor_IRQn       = -4,
    PendSV_IRQn             = -2,
    SysTick_IRQn            = -1,
    /* STM32 specific interrupts */
    EXTI0_IRQn              = 6,
    EXTI1_IRQn              = 7,
    EXTI2_IRQn              = 8,
    EXTI3_IRQn              = 9,
    EXTI4_IRQn              = 10,
    /* Add other peripheral interrupts as needed */
    CUSTOM_IRQ1             = 42,  /* Example custom interrupt */
    CUSTOM_IRQ2             = 43   /* Example custom interrupt */
} IRQn_Type;

/* Function prototypes */
static inline void NVIC_EnableIRQ(IRQn_Type IRQn) {
    if (IRQn >= 0) {
        NVIC_ISER0 = (1UL << ((uint32_t)IRQn & 0x1FUL));
    }
}

static inline void NVIC_DisableIRQ(IRQn_Type IRQn) {
    if (IRQn >= 0) {
        NVIC_ICER0 = (1UL << ((uint32_t)IRQn & 0x1FUL));
    }
}

static inline void NVIC_SetPendingIRQ(IRQn_Type IRQn) {
    if (IRQn >= 0) {
        NVIC_ISPR0 = (1UL << ((uint32_t)IRQn & 0x1FUL));
    }
}

static inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn) {
    if (IRQn >= 0) {
        NVIC_ICPR0 = (1UL << ((uint32_t)IRQn & 0x1FUL));
    }
}

static inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority) {
    /* Set priority for device specific interrupts */
    if (IRQn >= 0) {
        /* Cortex-M4 uses 4 priority bits by default */
        priority = priority << 4; /* Shift to most significant bits */

        /* Calculate the right register and bit position */
        uint32_t reg_offset = ((uint32_t)IRQn >> 2) * 4;
        uint32_t byte_offset = ((uint32_t)IRQn & 0x3) * 8;

        /* Clear and set the priority */
        volatile uint32_t *prio_reg = (volatile uint32_t *)(NVIC_BASE + 0x300UL + reg_offset);
        *prio_reg = (*prio_reg & ~(0xFFUL << byte_offset)) | (priority << byte_offset);
    }
}

/* Utility function for generating software interrupts */
static inline void NVIC_TriggerInterrupt(IRQn_Type IRQn) {
    NVIC_STIR = ((uint32_t)IRQn & 0xFF);
}

/* CMSIS-style function to get/set core registers */
static inline uint32_t __get_PSP(void) {
    uint32_t result;
    __asm volatile ("MRS %0, PSP" : "=r" (result));
    return result;
}

static inline void __set_PSP(uint32_t topOfProcStack) {
    __asm volatile ("MSR PSP, %0" : : "r" (topOfProcStack) : );
}

static inline uint32_t __get_MSP(void) {
    uint32_t result;
    __asm volatile ("MRS %0, MSP" : "=r" (result));
    return result;
}

static inline void __set_MSP(uint32_t topOfMainStack) {
    __asm volatile ("MSR MSP, %0" : : "r" (topOfMainStack) : );
}

static inline uint32_t __get_CONTROL(void) {
    uint32_t result;
    __asm volatile ("MRS %0, CONTROL" : "=r" (result));
    return result;
}

static inline void __set_CONTROL(uint32_t control) {
    __asm volatile ("MSR CONTROL, %0" : : "r" (control) : );
}

static inline uint32_t __get_PRIMASK(void) {
    uint32_t result;
    __asm volatile ("MRS %0, PRIMASK" : "=r" (result));
    return result;
}

static inline void __set_PRIMASK(uint32_t priMask) {
    __asm volatile ("MSR PRIMASK, %0" : : "r" (priMask) : );
}

static inline uint32_t __get_BASEPRI(void) {
    uint32_t result;
    __asm volatile ("MRS %0, BASEPRI" : "=r" (result));
    return result;
}

static inline void __set_BASEPRI(uint32_t basePri) {
    __asm volatile ("MSR BASEPRI, %0" : : "r" (basePri) : );
}

static inline uint32_t __get_FAULTMASK(void) {
    uint32_t result;
    __asm volatile ("MRS %0, FAULTMASK" : "=r" (result));
    return result;
}

static inline void __set_FAULTMASK(uint32_t faultMask) {
    __asm volatile ("MSR FAULTMASK, %0" : : "r" (faultMask) : );
}

static inline uint32_t __get_xPSR(void) {
    uint32_t result;
    __asm volatile ("MRS %0, xPSR" : "=r" (result));
    return result;
}

/* Instruction barriers */
static inline void __ISB(void) {
    __asm volatile ("isb");
}

static inline void __DSB(void) {
    __asm volatile ("dsb");
}

static inline void __DMB(void) {
    __asm volatile ("dmb");
}


#endif /* STM32F411_H_ */
