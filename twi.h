#ifndef TWI_H_
#define TWI_H_

#include<avr/io.h>

/* Macro for Error handling */
#define ERROR					twiError()

#define CPU_SPEED        16000000UL
#define TWI_SPEED        100000UL
#define TWI_PRESCALER    ((CPU_SPEED/TWI_SPEED)-16)/2
#define TWI_BIT_RATE     0x00

/* Master Transmitter status codes in TWSR */
#define START_TRANSMITTED			0x08
#define REPEATED_START				0X10
#define SLAW_TX_ACK				0X18
#define SLAW_TX_NACK				0X20
#define DATA_TX_ACK				0X28
#define DATA_TX_NACK				0X30
#define ARBITRATION_LOST_SLAW		        0x38

/* Master Transmitter response to TWCR */


/* Master Receiver status codes in TWSR */


/* Master Receiver response to TWCR */


/* Function Protypes */
void twiInit();

void twiStart();

void twiStop();

void twiWrite(uint8_t u8data);

uint8_t twiReadAck();

uint8_t twiReadNack();

uint8_t twiGetStatus();

void twiError();

#endif TWI_H_
