
#include <avr/io.h>
#include <stdint.h>
#include "pwm_functions.h"
 

void FPWM_init()
{
	TCCR0A |= ( 1 << COM0A1 );
	TCCR0A |= ( 1 << WGM00 ) | ( 1 << WGM01 );
	TCCR0B |= ( 1 << CS02 ) | ( 1 << CS00 );
	DDRD |= 1 << DDRD6;
}



void set_duty_cycle(uint8_t fpwm_parameter)
{
	OCR0A = fpwm_parameter; 
}
