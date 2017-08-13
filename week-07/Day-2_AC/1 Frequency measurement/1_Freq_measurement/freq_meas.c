#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

// TODO:
// Write the interrupt handlers

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
/* DS p170 Input capture unit
feladat: TC1 timert be�ll�tani
hint: tegnapi fPWM feladatban a TC0 timert �ll�tottuk be!
TC1 timer regisztere: TCR1A �s TCR1B, ezekbe be kell �ll�tani a 
compare output mode-ot, a Waveform  generator mode-ot �s a clock prescalert

*/
//Compare output mode @ Fast PWM (table 21-4) -> Clear OC1A/OC1B on Compare Match, 
// set OC1A/OC1B at BOTTOM (non-inverting mode)
	TCCR1A |= ( 1 << COM1A1 ) | ( 1 << COM1B1 );

//Waveform generation mode set. (table 21-6)
/* When a change of the logic level (an event) occurs on the Input Capture pin (ICP1), (..) a capture
will be triggered: the 16-bit value of the counter (TCNT1) is written to the Input Capture Register (ICR1).
Azaz, a 21-6 table legyen Fast PWM �s TOP = ICR1 m�d, ami a 14-es */
	
	TCCR1A |= ( 1 << WGM11 );
	TCCR1B |= ( 1 << WGM13 ) | ( 1 << WGM12 );
*/

// clock set to clkio/1024, mint a PWM-es feladatban, nem tudom mi�rt �pp /1024, 
// gondolom hogy min�l ink�bb lass�tsuk az �rajelet
	TCCR1B |= 1 << CS12;
	TCCR1B |= 1 << CS10;

// kell egy input capture kimenet - ez a PB0, ez default
// kell egy kimenet a PD6-on
	DDRD |= 1 << DDRD6;
	
// variable def
	prev = 0;
	last = 0;
	cntr_ovf = 0;	
}


static volatile uint16_t prev; // ez a TCNT �rt�ke amikor ICP1 1-re v�lt
static volatile uint16_t last; // ez TCNT �rt�ke amikor ICP1 miut�n lement null�ra �jra 1-re v�lt.
static volatile uint16_t ovf_value; // Create a variable which will be a counter variable, initialize it with 0.
static volatile uint16_t cntr_ovf; //ez a v�ltoz� sz�molja majd azt, h�nyszor �ri el a TCNT sz�ml�l� a plafon 65535-�t	

//interruptok
//megszak�t�s: timer ovrflow (h�nyszor �ri el a 65535-�t a TCNT sz�ml�l�
// m�g egy megszak�t�s: timer capture event, azaz amikor ICP1 elindul felfele
// megszak�t�s: week 2 day 3 - Functions, interrupts and timers t�mak�r.

ISR(TIMER1_CAPT_vect) //TCNT �rt�kei amikor a TCP v�lt
{
	ovf_value = cntr_ovf;
	cntr_ovf = 0;
	prev = last;
	last = ICR1;
}

ISR(TIMER1_OVF_vect)
{
	cntr_ovf ++;	
}

// TODO:
// Write this function. It returns the measured frequency in Hz

float get_freq()
{
	// The interrupts must be disabled while accessing variables which are used in interrupt handlers
	cli();
	// Copy the used variables as fast as possible.
	uint16_t last = last_reg_value;
	uint16_t prev = prev_reg_value;
	uint16_t ovf = ovf_value;
	sei();

	// This difference can be negative, that is why int32_t is used!
	// One of the variables should be casted to int32_t to avoid unexpected underflow
	int32_t diff = (int32_t)last - (int32_t)prev;

	// Steps will be always positive, so uint32_t can be used.
	// One of the variables should be casted to uint32_t to avoid unexpected overflof during multiplication
	uint32_t steps = ((uint32_t)ovf) * (OVF_STEPS) + diff;


	// One of the variables should be casted to float
	float period = TC1_STEP_TIME_S * (float)steps;
	float freq =  1 / period;

	// If you divide with zero in C the result will be NaN (not a number)
	// Check if the frequency is Nan, and return negative number in this case
	if (isnan(freq) || isinf(freq))
	return -1;
	else
	return freq;	
	

	
}
