/*
 * stm32f411_registers.h
 *
 *  Created on: Apr 27, 2025
 *      Author: Orr
 */

#ifndef NVIC_REGISTERS_H_
#define NVIC_REGISTERS_H_


#include <stdint.h>

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
#define NVIC_STIR0           (*(volatile uint32_t *)(STIR_BASE + 0x00UL))
#define NVIC_STIR1           (*(volatile uint32_t *)(STIR_BASE + 0x04UL))

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
    CUSTOM_IRQ1             = 38,  /* Example custom interrupt */
    CUSTOM_IRQ2             = 43   /* Example custom interrupt */
} IRQn_Type;

/* Function prototypes */
static inline void NVIC_EnableIRQ(IRQn_Type IRQn) {
	int ind  = IRQn / 32;
	switch (ind) {
		case 0:
	        NVIC_ISER0 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
			break;
		case 1:
	        NVIC_ISER1 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
	        break;
		default:
			break;
	}

}

static inline void NVIC_DisableIRQ(IRQn_Type IRQn) {
	int ind  = IRQn / 32;
	switch (ind) {
		case 0:
			NVIC_ICER0 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
			break;
		case 1:
			NVIC_ICER1 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
			break;
		default:
			break;
    }
}

static inline void NVIC_SetPendingIRQ(IRQn_Type IRQn) {
	int ind  = IRQn / 32;
	switch (ind) {
		case 0:
        NVIC_ISPR0 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
		break;
	case 1:
    	NVIC_ISPR1 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
		break;
	default:
		break;
	}
}

static inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn) {
	int ind  = IRQn / 32;
	switch (ind) {
		case 0:
			NVIC_ICPR0 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
			break;
		case 1:
			NVIC_ICPR1 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
			break;
		default:
			break;
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
	int ind  = IRQn / 32;
	switch (ind) {
		case 0:
			NVIC_STIR0 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
			break;
		case 1:
			NVIC_STIR1 |= (1UL << ((uint32_t)IRQn & 0x1FUL));
			break;
		default:
			break;
	}
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

/**
 * Function to read EXC_RETURN value
 */
__attribute__((always_inline)) static inline uint32_t read_exc_return(void) {
    uint32_t result;
    __asm volatile ("mov %0, lr" : "=r" (result));
    return result;
}

/**
 * Function to decode EXC_RETURN value
 */
const char* decode_exc_return(uint32_t exc_return) {
    switch(exc_return) {
        case 0xFFFFFFF1:
            return "Return to Handler mode, use MSP, no FP state";
        case 0xFFFFFFF9:
            return "Return to Thread mode, use MSP, no FP state";
        case 0xFFFFFFFD:
            return "Return to Thread mode, use PSP, no FP state";
        case 0xFFFFFFE1:
            return "Return to Handler mode, use MSP, FP state";
        case 0xFFFFFFE9:
            return "Return to Thread mode, use MSP, FP state";
        case 0xFFFFFFED:
            return "Return to Thread mode, use PSP, FP state";
        default:
            return "Unknown EXC_RETURN value";
    }
}
#endif /* NVIC_REGISTERS_H_ */
