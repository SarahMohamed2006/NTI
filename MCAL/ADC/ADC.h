
/*
 * ADC.h
 *
 * Created: 9/11/2026 8:29:54 PM
 *  Author: Sarah
 */ 

#ifndef ADC_H_
#define ADC_H_


#define ADMUX_Reg 	*((volatile u8*)0x27) 
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	
#define ADCH_Reg 	*((volatile u8*)0x25) 		
#define ADCL_Reg 	*((volatile u8*)0x24) 		


extern void ADC_init (void); // ADC Initialization 
extern u16 ADC_read (u8  channel_id); 

#endif /* ADC_H_ */
