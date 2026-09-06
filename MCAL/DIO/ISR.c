/*
 * ISR.c
 *
 * Created: 9/6/2026 7:56:58 PM
 *  Author: Missa
 */ 
#include "../SERVICE/STD_TYPES.h"
#include "../SERVICE/BIT_MATH.h"
#include "ISR.h"

/* Memory Mapped Registers for Interrupts */
#define MCUCR   *((volatile u8 *)0x55)
#define GICR    *((volatile u8 *)0x5B)
#define SREG    *((volatile u8 *)0x5F)

void initExternalInterrupts(void)
{
	/* 1. Set Interrupt 0 & 1 Trigger Condition to IOC (Any Logical Change) */
	/* INT0: ISC00 = 1, ISC01 = 0 */
	SET_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);

	/* INT1: ISC10 = 1, ISC11 = 0 */
	SET_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);

	/* 2. Enable INT0 and INT1 */
	SET_BIT(GICR, 6); // Enable INT0
	SET_BIT(GICR, 7); // Enable INT1

	/* 3. Enable Global Interrupt (GIE) */
	SET_BIT(SREG, 7);
}