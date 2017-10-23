/*
 * adc.c
 *
 * Created: 23.10.2017 16:24:22
 *  Author: KB1992PL
 */
#define F_CPU 8000000 
#include <util/delay.h>
#include <avr/io.h>
#include "adc.h"


void adc_init()
{
	ADC_DDR |= (1<<ADC_CS_PIN)|(1<<ADC_CLK_PIN)|(1<<3); //pin 3 for debug
	ADC_DDR &= ~(1<<ADC_DATA_PIN);
	ADC_PORT |= (1<<ADC_CS_PIN)|(1<<ADC_DATA_PIN);
}


uint8_t adc_read_byte()
{
	uint8_t data = 0;
	ADC_PORT &= ~(1<<ADC_CLK_PIN);
	ADC_PORT &= ~(1<<ADC_CS_PIN);
	for(int i = 0; i<8; i++)
	{
		ADC_PORT |= (1<<ADC_CLK_PIN);
		__asm(	"nop;");
				
		data = data*2;
		if (ADC_PIN&(1<<ADC_DATA_PIN)) 
		{
			data++;	
			PORTC ^=0x08;
		}
			
		ADC_PORT &= ~(1<<ADC_CLK_PIN);
		__asm(	"nop;");
	}
	ADC_PORT |=(1<<ADC_CS_PIN)|(1<<ADC_CS_PIN);
	return data;
}
