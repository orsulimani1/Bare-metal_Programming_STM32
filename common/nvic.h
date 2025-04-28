/*
 * nvic.h
 *
 *  Created on: Apr 27, 2025
 *      Author: Orr
 */

#ifndef NVIC_H_
#define NVIC_H_

/**
 * NVIC (Nested Vectored Interrupt Controller) Register Structure
 */
typedef struct {
     uint32_t ISER[8];    /* Offset: 0x000 (R/W) Interrupt Set Enable Registers */
	 uint32_t RESERVED0[24];
     uint32_t ICER[8];    /* Offset: 0x080 (R/W) Interrupt Clear Enable Registers */
	 uint32_t RESERVED1[24];
     uint32_t ISPR[8];    /* Offset: 0x100 (R/W) Interrupt Set Pending Registers */
	 uint32_t RESERVED2[24];
     uint32_t ICPR[8];    /* Offset: 0x180 (R/W) Interrupt Clear Pending Registers */
	 uint32_t RESERVED3[24];
     uint32_t IABR[8];    /* Offset: 0x200 (R/W) Interrupt Active Bit Registers */
	 uint32_t RESERVED4[56];
	 uint8_t  IP[240];    /* Offset: 0x300 (R/W) Interrupt Priority Registers (8-bit) */
	 uint32_t RESERVED5[644];
	 uint32_t STIR;       /* Offset: 0xE00 (W) Software Trigger Interrupt Register */
} NVIC_Type;

/* Memory mapping of NVIC registers */
#define NVIC_BASE           (0xE000E100UL)
#define NVIC                ((NVIC_Type *)NVIC_BASE)

#endif /* NVIC_H_ */
