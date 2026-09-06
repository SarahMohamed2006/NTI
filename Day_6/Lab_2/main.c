
#define F_CPU 1000000UL
#include "SERVICE/STD_TYPES.h"
#include "SERVICE/BIT_MATH.h"
#include "DIO/DIO_Int.h"
#include "DIO/ISR.h"

#include <util/delay.h>
#include <avr/interrupt.h>

volatile u8 mode = 0;

int main(void)
{
	u8 i = 0;

	/* Set PORTC (8 LEDs) as Output */
	DIO_voidSetPortDirection(DPORTC, 0xFF);

	/* Set PD2 (INT0) as Input with Internal Pull-up */
	DIO_voidSetPinDirection(DPORTD, PIN2, INPUT);
	DIO_voidSetPinValue(DPORTD, PIN2, HIGH);

	/* Initialize External Interrupt 0 */
	initExternalInterrupts();

	while (1)
	{
		if (mode == 0)
		{
			/* Animation 1: Shift Left */
			for (i = 0; i < 8; i++)
			{
				if (mode != 0) break;
				DIO_voidSetPortValue(DPORTC, (1 << i));
				_delay_ms(200);
			}
		}
		else if (mode == 1)
		{
			/* Animation 2: Flashing All LEDs */
			DIO_voidSetPortValue(DPORTC, OUTPUT);
			_delay_ms(300);
			DIO_voidSetPortValue(DPORTC, INPUT);
			_delay_ms(300);
		}
		else if (mode == 2)
		{
			/* Animation 3: Alternating Pattern */
			DIO_voidSetPortValue(DPORTC, 0xAA);
			_delay_ms(250);
			DIO_voidSetPortValue(DPORTC, 0x55);
			_delay_ms(250);
		}
	}
}

ISR(INT0_vect)
{
	mode++;
	if (mode > 2)
	{
		mode = 0;
	}
}
