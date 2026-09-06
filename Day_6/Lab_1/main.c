#define F_CPU 1000000UL

/* Include Header Files with Correct Folder Paths */
#include "SERVICE/STD_TYPES.h"
#include "SERVICE/BIT_MATH.h"
#include "DIO/DIO_Int.h"
#include "DIO/ISR.h"

#include <avr/interrupt.h>

int main(void)
{
	/* Initialize DIO Directions */
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN1, OUTPUT);

	DIO_voidSetPinDirection(DPORTD, PIN2, INPUT);
	DIO_voidSetPinDirection(DPORTD, PIN3, INPUT);

	/* Activate Internal Pull-Up Resistors */
	DIO_voidSetPinValue(DPORTD, PIN2, HIGH);
	DIO_voidSetPinValue(DPORTD, PIN3, HIGH);

	/* Initialize External Interrupts */
	initExternalInterrupts();

	while (1)
	{
		/* Main loop */
	}
}

/* Interrupt Service Routines */
ISR(INT0_vect)
{
	DIO_voidTogglePinValue(DPORTC, PIN0);
}

ISR(INT1_vect)
{
	DIO_voidTogglePinValue(DPORTC, PIN1);
}
