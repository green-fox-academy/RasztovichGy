/*
 * TC0_CTC_Test.c
 *
 * Created: 2017.05.11. 14:25:04
 * Author : Gyula
 */ 

#include <avr/io.h>
#define F_CPU 8000000
// 8millióra gyorsabban villog a led mint 16m-ra
#include <avr/delay.h>

void Init() {
//Set LED pin as output
	DDRB |= 1 << DDRB5;
	
}

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		/// toggle LED
		PINB |= 1 << PINB5;
		_delay_ms(500);
	}
}

