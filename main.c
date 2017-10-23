/*
 * Delay.c
 *
 * Created: 22.10.2017 19:06:23
 * Author : KB1992PL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "adc.h"
#define F_CPU	8000000

#define CONTROL_LED_PORT	PORTD
#define CONTROL_LED_DDR		DDRD

int main(void)
{
	TIMSK|=(1<<TOIE0);	//timer overflow interrupt enable
	TCCR0=0x01;			//timer divider: NO DIVIDE
	sei();
	CONTROL_LED_DDR = 0xff;
	adc_init();
    while (1) 
    {
		
    }
}

SIGNAL (TIMER0_OVF_vect)
{
	TCNT0 =56;	//25us
	PORTC^=0X08;	//debug signal
	CONTROL_LED_PORT = adc_read_byte();
}
