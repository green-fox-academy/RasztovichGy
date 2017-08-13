/*
 * 1 Dimming a LED in Fast PWM mode.c
 *
 * Created: 2017.06.12. 10:38:27
 * Author : Gyula
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include "pwm_functions.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>
#include <util/delay.h>


/*
Dimming a LED in Fast PWM mode
******************************
In this exercise the goal is to change the light intensity of a LED with PWM. 
You will set the TC0 timer to Fast PWM mode to generate PWM signals 
on the OC0A pin of the MCU.

Fist connect a LED (with a current limiting resistor) to the ATmega168PB
to the OC0A pin! 
((According to Fig 5-2 (p15), OC0A pin is on PD6 slot)).

Create the PWM related functions, definitions, variables etc. in 
a separate .c and .h file! This is necessary, because later on 
we will add more files to the project!
Write a function which initializes the TC0 timer in Fast PWM mode
Write a function which sets the duty cycle (0-100) of the PWM signal 
on the OC0A pin
The function should have one uint8_t parameter which value is between 0-100
Try out the init function and the duty cycle setter function
You should change the light intensity of the LED


*/


int main(void)
{
    /* elindítjuk az FPWM funkciót, megfûszerezzük egy kis duty scale beállítással
    10 halvány, 255 max fényerõ */
	FPWM_init();
	while (1){
		set_duty_cycle(10);
		_delay_ms(1000);
		set_duty_cycle(255);
		_delay_ms(1000);
   }
   
}

