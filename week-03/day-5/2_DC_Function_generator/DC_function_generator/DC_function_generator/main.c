﻿#include "ADC_driver.h"
#include "UART_driver.h"
#include "MCP4821_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include <avr/delay.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void SystemInit() {
	// Call the DAC driver init function
	MCP4821_Init();
   
    // Initialize the LED pin as output
    LED_DDR |= 1 << LED_DDR_POS;
    // Set the LED to off as default
    LED_PORT &= ~(1 << LED_PORT_POS);

    // Call the DAC driver init function
    ADC_Init();

    // Call the UART driver init function
    // Keep in mind that the UART will run at 115200 baud/sec
    UART_Init();

    // Enable interrupts globally, UART uses interrupts
    sei();
}

int main(void) {
    uint16_t adc_data;
	char buffer[255];

    // Don't forget to call the init function :)
    SystemInit();

    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP

    // Try printf
    printf("Startup...\r\n");

    // Infinite loop
    while (1) {
    	gets(buffer);
		puts(buffer);
    	float buffer_floated = atof(buffer);
    	int buffer_floated_ezerszerese = buffer_floated * 1000;
		_delay_ms(500); 
		
		MCP4821_Data_t dac_data; //ezzel a DAC struktúrát meghívjuk és elnevezzük dac_data változóként
		dac_data.data = buffer_floated_ezerszerese;
		dac_data.shutdown = 1;
		dac_data.gain = 0;
		dac_data.dont_care = 0;
		dac_data.start_zero = 0;
				
	/* a dac_data ilyen értékeket tárol (lásd mcp header)
		   uint16_t data:12;
	    uint16_t shutdown:1;
	    uint16_t gain:1;
	    uint16_t dont_care:1;
	    uint16_t start_zero:1;	*/
			
		//küldjük ki DAC-nak SPI-on a user inputot
		MCP4821_SendData(&dac_data);
					
		// ADC tester code
        adc_data = ADC_Read();
        //printf("%d\r\n", adc_data);
        // Send data as a number, not as a string.
        // The ADC result has 10bits, but we can only send 8bits at one on UART
        // If we want to display the result on the oscilloscope of the Data Visualizer plugin
        // we have to send the result on 8bits. If we shift down 2 times, we will get the top 8
        // bits of the data.
        UART_SendCharacter(adc_data >> 2);
	}
		
	return 0;
}

