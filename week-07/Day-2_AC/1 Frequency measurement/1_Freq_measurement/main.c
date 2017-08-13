#include "freq_meas.h"
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

/*
 *
 The goal is to write a program, which can measure a digital signal's
  frequency, which is connected to the ICP1 pin (PB0). 
 You should use the TC1 timer's input capture unit!
 create a new AtmelStudio project
 copy the following files to the project folder (next to the automatically 
 generated main.c file)
 overwrite the files if asked
 add the files to the project
 set up the compiler to compile printf with floating point support
 in the solution explorer
 right click on "Libraries"
 click on "Add library"
 in the opened windows tick "libprintf_flt"
 click on the "OK" button
 in the Project->Properties window
 click on "Toolchain"
 search for "AVR/GNU linker"
 click on "General"
 tick "Use vprintf library"
 save the settings with Ctrl+S
 write the code :)

 */


void system_init()
{
	LED_DDR |= 1 << LED_DDR_POS;
	freq_meas_init();
	UART_init();
	sei();
}

int main(void)
{

	// Don't forget to call the init function :)
	system_init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM((void *)UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, (void *)UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	// Infinite loop
	while (1) {
		// Generating an about 1Hz signal on the LED pin.
		// The printf call will also take some time, so this won't be exactly 1Hz.
		LED_PORT |= 1 << LED_PORT_POS;
		_delay_ms(500);
		LED_PORT &= ~(1 << LED_PORT_POS);
		_delay_ms(500);
		printf("%f Hz\n", get_freq());
	}
}
