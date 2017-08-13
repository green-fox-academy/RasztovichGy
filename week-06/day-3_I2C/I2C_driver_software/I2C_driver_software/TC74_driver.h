// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1
//TODO
//Define the TC74A0 address
// TC74 datasheet page 15 -> address = 1001 000
#define TC74_ADDR 0b10010000
//nem eliras az adat tenyleg 7 biten van tarolva, a nyolcadik bit a végén van ami read vagy write
// ezert elvben shiftelni kellene 
// de egyszerubb eleve azt az egy nullát beírni a végére.

void TWI_init(void);
void TWI_start(void);
void TWI_write(uint8_t u8data);
void TWI_stop(void);
uint8_t TWI_read_nack(void);
uint8_t TWI_read_ack(void);

#endif // _TC74_DRIVER_H
