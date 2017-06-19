#include "TC2_PWM_driver.h"
#include <avr/io.h>
#include <stdint.h>

void TC2_fast_pwm_init()
{
	// 
	TCCR2A |= 1 << WGM21;
	TCCR2A |= 1 << WGM20;

	// 
	TCCR2A |= 1 << COM2A1;

	// PinB3 kimenetnek állítása
	DDRB |= 1 << DDRB3;
	

	// Set clock speed to 16MHz/128 (128 prescaler)
	TCCR2B |= 1 << CS20;
	TCCR2B |= 1 << CS22;

	// Set OCR0A register to generate 50% duty cycle
	OCR2A = 10;	// 255 is max duty cycle
}

void TC2_set_duty(uint8_t duty)
{
	OCR2A = 255 * (float)(duty) / 100;
}
