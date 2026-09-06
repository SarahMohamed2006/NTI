/*
 * DIO_Private.h
 *
 * Created: 9/6/2026 5:22:06 AM
 *  Author: Sarah
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DDRA   	*((volatile u8 *)0x3A)
#define PORTA   *((volatile u8 *)0x3B)
#define PINA   	*((volatile u8 *)0x39)


#define DDRB   	*((volatile u8 *)0x37)
#define PORTB   *((volatile u8 *)0x38)
#define PINB   	*((volatile u8 *)0x36)


#define DDRC   	*((volatile u8 *)0x34)
#define PORTC   *((volatile u8 *)0x35)
#define PINC   	*((volatile u8 *)0x33)


#define DDRD   	*((volatile u8 *)0x31)
#define PORTD   *((volatile u8 *)0x32)
#define PIND   	*((volatile u8 *)0x30)

#define DIO_CONCAT_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define DIO_CONCAT(b7,b6,b5,b4,b3,b2,b1,b0)         DIO_CONCAT_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)

#define DIO_PORTA_DIRECTION  DIO_CONCAT(DIO_PORTA_PIN7_DIR,DIO_PORTA_PIN6_DIR,DIO_PORTA_PIN5_DIR,DIO_PORTA_PIN4_DIR,DIO_PORTA_PIN3_DIR,DIO_PORTA_PIN2_DIR,DIO_PORTA_PIN1_DIR,DIO_PORTA_PIN0_DIR)
#define DIO_PORTB_DIRECTION  DIO_CONCAT(DIO_PORTB_PIN7_DIR,DIO_PORTB_PIN6_DIR,DIO_PORTB_PIN5_DIR,DIO_PORTB_PIN4_DIR,DIO_PORTB_PIN3_DIR,DIO_PORTB_PIN2_DIR,DIO_PORTB_PIN1_DIR,DIO_PORTB_PIN0_DIR)
#define DIO_PORTC_DIRECTION  DIO_CONCAT(DIO_PORTC_PIN7_DIR,DIO_PORTC_PIN6_DIR,DIO_PORTC_PIN5_DIR,DIO_PORTC_PIN4_DIR,DIO_PORTC_PIN3_DIR,DIO_PORTC_PIN2_DIR,DIO_PORTC_PIN1_DIR,DIO_PORTC_PIN0_DIR)
#define DIO_PORTD_DIRECTION  DIO_CONCAT(DIO_PORTD_PIN7_DIR,DIO_PORTD_PIN6_DIR,DIO_PORTD_PIN5_DIR,DIO_PORTD_PIN4_DIR,DIO_PORTD_PIN3_DIR,DIO_PORTD_PIN2_DIR,DIO_PORTD_PIN1_DIR,DIO_PORTD_PIN0_DIR)


#endif /* DIO_PRIVATE_H_ */