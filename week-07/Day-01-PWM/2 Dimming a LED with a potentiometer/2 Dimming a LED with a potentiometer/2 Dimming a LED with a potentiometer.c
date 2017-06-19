/*
 * 2 Dimming a LED with a potentiometer.c
 *
 * Created: 2017.06.12. 17:18:34
 * Author : Gyula
 */ 


#include <avr/io.h>
#include "pwm_functions.h"
#include "ADC_driver.h"

#define F_CPU 16000000
#include <util/delay.h>


/*
Dimming a LED with a potentiometer
**********************************
The goal is to change the LED's light intensity based on the 
potentiometer's voltage level.

At first add a potentiometer to the previous circuit.

Exercise steps:

Create a new AtmelStudio project
Copy the previous exercise's file to the new project and add them to the project
Add the ADC driver files to the project
You can use your solution of a previous workshop OR
You can use our solution of a previous workshop
In main write a code that reads the voltage from the potentiometer and based 
on that changes the duty cycle of the PWM signal on the OC0A pin
Test the code by rolling the potentiometer

*/

void system_init()
{
	FPWM_init();
	ADC_init();
}


int main(void)
{
    system_init();
	while (1) {
		float adc_data = ADC_read();
		//set_duty_cycle(10);
		//_delay_ms(1000);
		set_duty_cycle(adc_data / ADC_DATA_MAX * 100);
		//_delay_ms(1000);
   }
   
}

