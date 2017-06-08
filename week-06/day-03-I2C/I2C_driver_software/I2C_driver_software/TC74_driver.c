#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
	// TODO:
// MCU-t kell alkalmassa tenni a TC74 adatainak fogadasara
	// Set Prescaler to 4
// datasheet 27-8 (page 309) TWI status register
// according to the table, TWPS1 must set to 0 (default), TWPS0 set to 1
	TWSR |= 1 << TWPS0;
	// TODO:
	// Set SCL frequency = 16000000 / (16 + 2 * 48 * 4) = 40 kHz
// 27.5.2. paragraph page 285: SCL freq = CPU clock freq / ( 16 + 2*TWBR*prescalervalue)
// where TWBR: Value of the TWI Bit Rate Register TWBRn -> 27.9.1 paragraph
// TWBR-t én állítom be
// Azért legyen TWBR = 48 dec, mert a TC74 adatlapján (2. oldal characteristics)
// meg van adva hogy clock freq 10-100 kHz közötti tartományban működik,
// azaz SCL freq legyen 10..100 kHz között, 
// 16000000/(16+2X*4) := 10...100 kHz -> X ránézek és látom hogy 16millió / 400 = 40000,
// 16+2X*4 = 400 -> X=384/8 azaz X=48 ami hexában 0x30 ami binárisan 0b110000

	// So set the correct register to 0x30
// a TWBR register 8 bit hosszú, ide kell betenni a 110000-t, azaz a 	
// TWBR5 legyen 1 és TWBR4 legyen 1 többi 0
/* most ne így mert biztosabb
	TWBR |= 1 << TWBR5;
	TWBR |= 1 << TWBR4; */
	TWBR = 0x30;
	// TODO
	// Enable TWI
//27.9.5 TWI control reg: TWEN bit enables TWI operation and activates TWI interface
	TWCR |= 1 << TWEN;
}

void TWI_start(void)
{
	//TODO
	//Send start signal
//TWCR TWSTA a start condition
	TWCR |= 1 << TWSTA;

	// TODO:
	// Wait for TWINT Flag set. This indicates that
	// the START condition has been transmitted.
	TWCR |= 1 << TWINT;
}

void TWI_stop(void)
{
	// TODO
	// Send stop signal
	TWCR |= 1 << TWSTO;
}

uint8_t TWI_read_ack(void)
{
	//TODO
	//Read byte with ACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.

}


uint8_t TWI_read_nack(void)
{
	//TODO
	//Read byte with NACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.

}

void TWI_write(uint8_t u8data)
{
	//TODO
	//Load DATA into TWDR Register. Clear TWINT
	//bit in TWCR to start transmission of data.
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.

}

//TODO
//Write a function that communicates with the TC74A0.
//The function need to be take the address of the ic as a parameter.
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.


//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.
