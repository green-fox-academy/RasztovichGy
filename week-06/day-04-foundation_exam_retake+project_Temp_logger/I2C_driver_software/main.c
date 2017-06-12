#include "TC74_driver.h"
#include "UART_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

uint8_t cntr = 0;
const uint8_t cntr_max = 20;
ISR(TIMER0_OVF_vect) { //interrupt fuunkcioja
	if (cntr < cntr_max) {
		cntr++;
	}
	else {
		printf("%d\n", readtemp()); //ezzel timer interrupttal iratom ki a hõfokot
		PINB |= 1 << PINB5; //ezzel ledet villogtatunk
		cntr = 0;
	}
}


void timer_init()
{
	// Enable the TC0 overflow interrupt
	TIMSK0 |= 1 << TOIE0;
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	TCCR0B |= 1 << CS00;
	TCCR0B |= 1 << CS02;
	// Set the PB5 LED pin to output
	DDRB |= 1 << DDRB5;
}


void system_init()
{
	//TODO
	// Call the TWI driver init function
	TWI_init();
	//TODO
	//Init the uart
	UART_init();
}

int main(void)
{

	// Don't forget to call the init function :)
	system_init();
	timer_init();
	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	sei();

	
	// Infinite loop
	while (1) {
		//TODO
		//Write the temperature frequently.
				//printf("%d\n", readtemp());
				//_delay_ms(1000);
		//TODO
		//Advanced: Don't use delay, use timer.
		 //megy ez magától :)
		//TODO
		//Blink the led to make sure the code is running

	}
}
