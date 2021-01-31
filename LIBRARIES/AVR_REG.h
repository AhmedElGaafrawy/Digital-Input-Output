/*
 * AVR_REG.h
 *
 *  Created on	: Mar 31, 2020
 *  Version		: 1.0.0
 *  Author		: Ahmed El-Gaafarwy
 */

#ifndef AVR_REG_H_
#define AVR_REG_H_

/*
 * NULL
 */
#define NULL  ((void*)0)

typedef struct
{
	/*TWI*/
	uint_8 TWBR;
	uint_8 TWSR;
	uint_8 TWAR;
	uint_8 TWDR;

	/*ADC*/
	uint_8 ADCL;
	uint_8 ADCH;
	uint_8 ADCSRA;
	uint_8 ADMUX;
	uint_8 ACSR;

	/*UART*/
	uint_8 UBRRL;
	uint_8 UCSRB;
	uint_8 UCSRA;
	uint_8 UDR;

	/*SPI*/
	uint_8 SPCR;
	uint_8 SPSR;
	uint_8 SPDR;

	/*PORT->D*/
	uint_8 PIND;
	uint_8 DDRD;
	uint_8 PORTD;

	/*PORT->C*/
	uint_8 PINC;
	uint_8 DDRC;
	uint_8 PORTC;

	/*PORT->B*/
	uint_8 PINB;
	uint_8 DDRB;
	uint_8 PORTB;

	/*PORT->A*/
	uint_8 PINA;
	uint_8 DDRA;
	uint_8 PORTA;

	/*Internal EEPROM*/
	uint_8 EECR;
	uint_8 EEDR;
	uint_8 EEARL;
	uint_8 EEERH;

	/*UBRRH*/
	uint_8 UCSRC;

	/*WDT*/
	uint_8 WDTCR;
	uint_8 ASSR;

	/*TIMER 2*/
	uint_8 OCR2;
	uint_8 TCNT2;
	uint_8 TCCR2;

	/*TIMER 1*/
	uint_8 ICR1L;
	uint_8 ICR1H;

	uint_8 OCR1BL;
	uint_8 OCR1BH;
	uint_8 OCR1AL;
	uint_8 OCR1AH;

	uint_8 TCNT1L;
	uint_8 TCNT1H;

	uint_8 TCCR1B;
	uint_8 TCCR1A;


	/**/
	uint_8 SFIOR;
	uint_8 OCDR;


	/*Timer 0*/
	uint_8 TCNT0;
	uint_8 TCCR0;

	/*EXTI*/
	uint_8 MCUCSR;
	uint_8 MCUCR;

	/*TWI*/
	uint_8 TWCR;

	/**/
	uint_8 SPMCR;

	/*TIMER*/
	uint_8 TIFR;
	uint_8 TIMSK;

	/*EXTI*/
	uint_8 GIFR;
	uint_8 GICR;

	/*Timer 0*/
	uint_8 OCR0;

	uint_8 SPL;
	uint_8 SPH;

	/*PSW*/
	uint_8 SREG;
}AVR_st;


/*I/O MEMORY Address*/
#define ATMEGA32		((AVR_st*)0x20)


/*Shared Location*/
#define UBRRH		UCSRC
#define OSCCAL 		OCDR



#endif /* AVR_REG_H_ */
