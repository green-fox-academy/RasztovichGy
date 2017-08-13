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

	//DDR bekapcsolása - megadjuk az interruptot
	DDRC |= (1<<DDRC1);
	
	//engedélyezi az interruptot
	sei();
}
int main(void){
	
	init();

	//örökké fut, ha a while feltétele (1)
	while(1)
	{
		//led felvillanás cikluson belüli engedélyezés
		PINC |= (1<<PINC1);
		//led villogás sebessége
		_delay_ms(100);
	}
}