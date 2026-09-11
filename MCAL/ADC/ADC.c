/*
 * ADC.c
 *
 * Created: 9/11/2026 8:29:28 PM
 *  Author: Sarah
 */ 
#include "../SERVICE/bit_math.h"
#include "../SERVICE/std_types.h"
#include "ADC.h"

void ADC_init(void) {
	ADMUX_Reg &= ~(1 << 7);
	ADMUX_Reg |=  (1 << 6); 
    ADMUX_Reg &= ~(1 << 5); 
	ADCSRA_Reg |= (1 << 2) | (1 << 1) | (1 << 0);  
	ADCSRA_Reg |= (1 << 7); 
}

u16 ADC_read(u8 channel_id) {
	ADMUX_Reg = (ADMUX_Reg & 0xE0) | ( channel_id & 0x1F); 
    ADCSRA_Reg |= (1 << 6); 

	while (!(ADCSRA_Reg & (1 << 4)));

	ADCSRA_Reg |= (1 << 4); 

	u16 digital_value = ADCL_Reg; 
	digital_value |= (ADCH_Reg << 8);
	return digital_value;
}


