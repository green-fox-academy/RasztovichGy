// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1
//TODO
//Define the TC74A0 address
// TC74 datasheet page 15 -> address = 1001 000
#define TC74_ADDR 0b1001000
//nem eliras az adat tenyleg 7 biten van tarolva

void TWI_init(void);
void TWI_start(void);
void TWI_write(uint8_t u8data);
void TWI_stop(void);
uint8_t TWI_read_nack(void);
uint8_t TWI_read_ack(void);
int8_t readtemp(void);

#endif // _TC74_DRIVER_H
