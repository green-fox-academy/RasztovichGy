#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "MCP4821_driver.h"

void MCP4821_Init() {
    // TODO:
    // Initialize the SPI related pins. Use the definitions from MCP4821_driver.h!
	SPI_MOSI_DDR |= 1 << SPI_MOSI_DDR_POS; //enable PB3 port on MCU as MOSI
	SPI_SS_DDR |= 1 << SPI_SS_DDR_POS; //enable PB2 port on MCU as Serial select
	SPI_SCK_DDR |= 1 << SPI_SCK_DDR_POS; //enable PB5 port on MCU as Clock sign
/* fentiek analógok ezzel:	DDRB |= 1 << DDRB3;
							DDRB |= 1 << DDRB2;
							DDRB |= 1 << DDRB5; */			
	// TODO:
    // Pull SS pin to high!
	SPI_SS_PORT |= 1 << SPI_SS_PORT_POS; //enable PB2 port on MCU as Serial select
/* ez analóg ezzel: PORTB |= 1 << PORTB2; */


    // TODO:
    // Set the SPI mode (CPOL and CPHA). Use the definitions from MCP4821_driver.h!

/* analógia: SPCR |= 1 << CPOL;  -> így lenne az SPCR regiszter 3. bitje, aminek a neve (nem SPCR3) CPOL=1. 
									DE! most a feladat az, hogy a mód legyen CPOL=0, CPHA=0, ami viszont a default értéke az SPCR regiszternek. 
									Azaz, most nem kell állítani ezen a regiszteren!
	analógia: SPCR |= 1 << CPHA; -> hasonlóan nem szükséges most. */
	
//	az mcp4821 driver nyelve szerint ezt kellene írni, de most felesleges mert alapértelmezésben 0 mindkettõ: 
//	SPCR &= ~(1 << CPOL); Ha nullát kell betenni valahova: nem lehet nullával egyenlõvé tenni! Össze kell ÉSNEGÁLTolni 1-el. 
//	SPCR &= ~(1<< CPHA);


    // TODO:
    // Set master mode
// Az SPCR regiszter 4. bitjét kell egyesre állítani (Datasheet 24.5.1.) szerint, aminek a neve (nem SPCR5) MSTR.
	SPCR |= 1 << MSTR;

    // TODO:
    // Set the clock frequency. Use the definitions from MCP4821_driver.h, azaz abban a fájban meg van adva hogy 0b11 legyen!
	//Table 24-5 -> clock freq az SPCR register 0. és 1. bitje, nevük SPR0 és SPR1. Most megadták, hogy a lassítás 128 legyen.
	SPCR = SPI_SPR;
//ha nem lenne driver.h fájl:
// SPCR |= 1 << SPR0;
// SPCR |= 1 << SPR1;


    // TODO:
    // Enable SPI peripheral
/*24.5.1.    SPI Control Register 0 -> Bit 6 – SPE:?SPI0 
Enable When the SPE bit is written to one, the SPI is enabled. */
	SPCR |= 1 << SPE;
}

void MCP4821_SendRawData(uint16_t data) {
    // TODO:
    // Pull SS low
	SPI_SS_PORT &= ~(1 << SPI_SS_PORT_POS); //nullát nem lehet shiftelni, csak ÉSnegált 1-et.

    // TODO:
    // Put the top 8bits of the data to the SPI shift register
/* DS: 24.5.3.    SPI Data Register. Ez azt mutatja, hogy az SPDR register 8 bites. A data viszont 16, hiszen így definiálták a sendrawdata függvényben (uint16_t!). ezeket az adatokat (változó neve: "data" kell betenni a 8bites regiszterbe! */
	SPDR = data >> 8;

    // TODO:
    // Wait for the end of the transmission
/* ide kell egy while fgv!
239. old: Bit 7 – SPIF:?SPI Interrupt Flag; When a serial transfer is complete, the SPIF Flag is set. 
An interrupt is generated if SPIE in SPCR is set and global interrupts are enabled. 
-> azaz, az interruptot megcsinálja magától! Nekem nem kell most a whájl-ba feltételt adni!
*/
	while( !(SPSR & (1 << SPIF)));	//note: while (a zárójelbeíromafeltételt) {a hasba hogy mit csináljon)

    // You have to read the SPDR register to clear the SPIF flag after the end of transmission
    volatile uint8_t dummy_variable = SPDR;

    // TODO:
    // Put the bottom 8bits of the data to the SPI shift register
	SPDR = data;
	
    // TODO:
    // Wait for the end of the transmission
	while( !(SPSR & (1 << SPIF)));

    // You have to read the SPDR register to clear the SPIF flag after the end of transmission
    dummy_variable = SPDR;

    // TODO:
    // Pull SS high
	SPI_SS_PORT |= 1 << SPI_SS_PORT_POS;
}

void MCP4821_SendData(MCP4821_Data_t* data) {
    // Convert the data variable to a 16bit number with memcpy()
    // Then use the MCP4821_SendRawData() function to send the data
    uint16_t buffer;
    memcpy(&buffer, data, sizeof(MCP4821_Data_t));
    MCP4821_SendRawData(buffer);
}
