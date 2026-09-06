/*
 * DIO_Prog.c
 *
 * Created: 9/6/2026 5:13:38 AM
 *  Author: Sarah
 */ 

#include "../SERVICE/STD_TYPES.h"
#include "../SERVICE/BIT_MATH.h"


#include "DIO_Int.h"
#include "DIO_Private.h"
#include "DIO_Config.h"


void DIO_voidInitialization(void)
{
	DDRA = DIO_PORTA_DIRECTION;
	DDRB = DIO_PORTB_DIRECTION;
	DDRC = DIO_PORTC_DIRECTION;
	DDRD = DIO_PORTD_DIRECTION;
}

void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{
	if(PortID < 4 && PinID < 8)
	{
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case DPORTA: SET_BIT(DDRA, PinID); break;
				case DPORTB: SET_BIT(DDRB, PinID); break;
				case DPORTC: SET_BIT(DDRC, PinID); break;
				case DPORTD: SET_BIT(DDRD, PinID); break;
			}
		}
		else if(Direction == INPUT)
		{
			switch(PortID)
			{
				case DPORTA: CLR_BIT(DDRA, PinID); break;
				case DPORTB: CLR_BIT(DDRB, PinID); break;
				case DPORTC: CLR_BIT(DDRC, PinID); break;
				case DPORTD: CLR_BIT(DDRD, PinID); break;
			}
		}
		else
		{
			
		}
	}
	else
	{
		
	}
}
void DIO_voidSetPinValue(u8 PortID, u8 PinID, u8 Value)
{
	if(PortID < 4 && PinID < 8)
	{
		if(Value == HIGH)
		{
			switch(PortID)
			{
				case DPORTA: SET_BIT(PORTA, PinID); break;
				case DPORTB: SET_BIT(PORTB, PinID); break;
				case DPORTC: SET_BIT(PORTC, PinID); break;
				case DPORTD: SET_BIT(PORTD, PinID); break;
			}
		}
		else if(Value == LOW)
		{
			switch(PortID)
			{
				case DPORTA: CLR_BIT(PORTA, PinID); break;
				case DPORTB: CLR_BIT(PORTB, PinID); break;
				case DPORTC: CLR_BIT(PORTC, PinID); break;
				case DPORTD: CLR_BIT(PORTD, PinID); break;
			}
		}
		else
		{
			
		}
	}
	else
	{
		
	}
}

u8 DIO_u8ReadPinValue(u8 PortID, u8 pinID){
	
	u8 val=0;
	if(PortID<4 && pinID<8){
		
		switch (PortID) {
			case DPORTA:val= GET_BIT(PINA,pinID) ; break;

			case DPORTB:val= GET_BIT(PINB,pinID); break;

			case DPORTC:val= GET_BIT(PINC,pinID) ;break;

			case DPORTD:val= GET_BIT(PIND,pinID) ; break;
		}

		}else{}
		return val;
		
	}


void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
	{
		switch (PortID)
		{
			case DPORTA: DDRA = Direction; break;
			case DPORTB: DDRB = Direction; break;
			case DPORTC: DDRC = Direction; break;
			case DPORTD: DDRD = Direction; break;
			default:  break;
		}
	}

void DIO_voidSetPortValue(u8 PortID, u8 Value)
	{
		switch (PortID)
		{
			case DPORTA: PORTA = Value; break;
			case DPORTB: PORTB = Value; break;
			case DPORTC: PORTC = Value; break;
			case DPORTD: PORTD = Value; break;
			default:  break;
		}
	}
	
u8 DIO_u8ReadPortValue(u8 PortID)
{
	u8 val = 0;
	switch (PortID)
	{
		case DPORTA: val = PINA; break;
		case DPORTB: val = PINB; break;
		case DPORTC: val = PINC; break;
		case DPORTD: val = PIND; break;
		default: break;
	}
	return val;
}
	
void DIO_voidTogglePinValue(u8 PortID, u8 PinID)
{
	if(PortID < 4 && PinID < 8)
	{
		switch(PortID)
		{
			case DPORTA: TOG_BIT(PORTA, PinID); break;
			case DPORTB: TOG_BIT(PORTB, PinID); break;
			case DPORTC: TOG_BIT(PORTC, PinID); break;
			case DPORTD: TOG_BIT(PORTD, PinID); break;
		}
	}
}