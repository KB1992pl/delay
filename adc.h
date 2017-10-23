/*
 * adc.h
 *
 * Created: 23.10.2017 16:24:13
 *  Author: KB1992PL
 * Functions to communicate with TLC549 serial ADC
 */ 


#ifndef ADC_H_
#define ADC_H_

#define ADC_PORT		PORTC
#define ADC_PIN			PINC
#define ADC_DDR			DDRC
#define ADC_CS_PIN		2	 
#define ADC_CLK_PIN		0
#define ADC_DATA_PIN	1

void adc_init();
uint8_t adc_read_byte();



#endif 