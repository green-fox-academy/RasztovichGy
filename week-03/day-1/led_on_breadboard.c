/*
 * Led_on_breadboard.c
 *
 * Created: 2017.05.15. 17:31:13
 * Author : Gyula
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

ISR(PCINT0_vect){
	// Toggle the LED - from PC1
	
	PINC |= (1<<PINC1);
}
void init(){

	//DDR bekapcsol�sa - megadjuk az interruptot
	DDRC |= (1<<DDRC1);
	
	//enged�lyezi az interruptot
	sei();
}
int main(void){
	
	init();

	//�r�kk� fut, ha a while felt�tele (1)
	while(1)
	{
		//led felvillan�s cikluson bel�li enged�lyez�s
		PINC |= (1<<PINC1);
		//led villog�s sebess�ge
		_delay_ms(100);
	}
}