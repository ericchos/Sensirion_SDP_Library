#ifndef SENSIRION_H_
#define SENSIRION_H_

#include "twi.h"
#include <Arduino.h> 

/* SDP 600 address with write bit (0) */
#define SDP_600_ADDR_W   0x80

/* SDP 600 address with read bit (1) */
#define SDP_600_ADDR_R   0x81

/* SDP Command to read differential pressure */
#define SDP_600_READ     0xF1

/* I2C Command to do a soft reset on sensirion sensor */
#define SOFT_RESET       0xFE
#define SGM_7006_ADDR    0x40

/* Do a soft reset on sensor */
void sensirion_reset();

/* Initializes the sensirion sensor */
void sensirion_init();

/* Reads the digital reading from the sensirion sensor */
int16_t sensirion_read();

#endif
