
#include <avr/io.h>
#include <stdint.h>
#include "pwm_functions.h"

/*
Task:
*****
Create the PWM related functions, definitions, variables etc. in 
a separate .c and .h file! This is necessary, 
because later on we will add more files to the project!
Write a function which initializes the TC0 timer in Fast PWM mode
Write a function which sets the duty cycle (0-100) of the PWM signal on the OC0A pin
	The function should have one uint8_t parameter which value is between 0-100
Try out the init function and the duty cycle setter function
	You should change the light intensity of the LED

*/


void FPWM_init()
{
/* Fast PWM mode 20.7.3.  The counter counts from BOTTOM to TOP, then restarts from
BOTTOM. TOP is defined0xFF when WGM0[2:0]=0x3. TOP is defined as OCR0A when
WGM0[2:0]=0x7.
20.9 p152 Register description: amit �ll�tani kell, az a TC0 register.
TCCR0A register 0-1 bitje a WGM00 �s WGM01.  6-7. bit a COM0A1 �s COM0A0.
Miket �ll�tsunk be? -> v�lasz: Table 20-4 Compare output mode, fast PWM. 
Ahol OC0A disconnected, nem lesz j�, hiszen a PD6 pin van az OC (l�sd fig 5-2),
illetve nem invert�lunk hanem norm�l jel kell --> a 3. sorban l�v� 1-0 be�ll�t�s kell
Nosza! */
	TCCR0A |= ( 1 << COM0A1 );
/*
Most akkor �ll�tsuk be a WGM biteket, na de mire?  */
	TCCR0A |= ( 1 << WGM00 ) | ( 1 << WGM01 );
		
// most lass�tsuk le az MCU proci �rajel�t 1/1024-re
// ehhez a TCCR0B CS02..CS00 bitjeit kell be�ll�tani a table 20-10 szerint
	TCCR0B |= ( 1 << CS02 ) | ( 1 << CS00 );
  
/* PD6 pint nyissuk meg. A PD6-b�l kap �ramot a breadboard, azaz az kimenet!
ezt be kell �ll�tani:
	19.4.9: DDRD regiszter! */
	DDRD |= 1 << DDRD6;
}


/* v�g�l meg kell �rni a duty cycle be�ll�t�s funkci�t.
Nem kell t�ldr�m�zni, sim�n a main-ben be�rjuk a z�r�jelbe a param�tert
ami a feladatki�r�s szerint 10..100 k�z�tti. 
Am�gy ez szab�lyozza a led f�nyer�t.*/
void set_duty_cycle(uint8_t fpwm_parameter)
{
	OCR0A = fpwm_parameter; 
}
