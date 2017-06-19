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
feladat: TC1 timert beállítani
hint: tegnapi fPWM feladatban a TC0 timert állítottuk be!
TC1 timer regisztere: TCR1A és TCR1B, ezekbe be kell állítani a 
compare output mode-ot, a Waveform  generator mode-ot és a clock prescalert

*/
//Compare output mode @ Fast PWM (table 21-4) -> Clear OC1A/OC1B on Compare Match, 
// set OC1A/OC1B at BOTTOM (non-inverting mode)
	TCCR1A |= ( 1 << COM1A1 ) | ( 1 << COM1B1 );

//Waveform generation mode set. (table 21-6)
/* When a change of the logic level (an event) occurs on the Input Capture pin (ICP1), (..) a capture
will be triggered: the 16-bit value of the counter (TCNT1) is written to the Input Capture Register (ICR1).
Azaz, a 21-6 table legyen Fast PWM és TOP = ICR1 mód, ami a 14-es */
	
	TCCR1A |= ( 1 << WGM11 );
	TCCR1B |= ( 1 << WGM13 ) | ( 1 << WGM12 );
*/

// clock set to clkio/1024, mint a PWM-es feladatban, nem tudom miért épp /1024, 
// gondolom hogy minél inkább lassítsuk az órajelet
	TCCR1B |= 1 << CS12;
	TCCR1B |= 1 << CS10;

// kell egy input capture kimenet - ez a PB0, ez default
// kell egy kimenet a PD6-on
	DDRD |= 1 << DDRD6;
}

// TODO:
// Write this function. It returns the measured frequency in Hz

//interruptok
//megszakítás: timer ovrflow (hányszor éri el a 65535-öt a TCNT számláló
// még egy megszakítás: timer capture event, azaz amikor ICP1 elindul felfele
// megszakítás: week 2 day 3 - Functions, interrupts and timers témakör. 


uint16_t prev; // ez a TCNT értéke amikor ICP1 1-re vált
uint16_t last; // ez TCNT értéke amikor ICP1 miután lement nullára újra 1-re vált.
uint16_t cntr = 0; // Create a variable which will be a counter variable, initialize it with 0.
const uint16_t cntr_max = 65535; // This will be the maximal value of our counter. 
uint16_t counter_ovf; //ez a változó számolja majd azt, hányszor éri el a TCNT számláló a plafon 65535-öt	

ISR(TIMER1_OVF_vect)
{
	// számoljuk meg, hány overflow történik
	// és azt tároljuk el egy számba, késõbb abból számoljuk a T periódusdõt
	if (cntr < cntr_max) { //nem kellene egy for ciklus ahhoz hogy a cntr 1-tõl elinduljon?
		cntr++;
		} 
	counter_ovf = cntr; 
}

ISR(TIMER1_CAPT_vect)
{
	// számoljuk meg, hány overflow történik
	// és azt tároljuk el egy számba, késõbb abból számoljuk a T periódusdõt
	if (cntr < cntr_max) { //nem kellene egy for ciklus ahhoz hogy a cntr 1-tõl elinduljon?
		cntr++;
	}
uint16_t counter_ovf = cntr; //ez a változó számolja majd azt, hányszor éri el a TCNT számláló a plafon 65535-öt	}
}





float get_freq()
{
	
/*
3 globális változó kell, az interruptokat számolja kettõ,
a 3. 
*/	
	
	uint16_t temp = ICR1;
	
}
