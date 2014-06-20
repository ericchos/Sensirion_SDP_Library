#ifndef TWI_H_
#define TWI_H_

#include <avr/io.h>
#include <Arduino.h>
/* Macro for Error Handling */
#define ERROR						twiError()

/* Macros to Define TWI Bit Rate which is set in TWBR */
#define CPU_SPEED					16000000UL /* 16MHz */
#define TWI_SPEED					100000UL /* 100KHz */
#define TWI_BIT_RATE				((CPU_SPEED/TWI_SPEED)-16)/2

#define TW_START					0xA4 /* Send start condition */
#define TW_READY					(TWCR & 0x80) /* Ready when TWINT returns 1 */

/* I2C Status codes in TWSR register */
/* Master Transmitter/Receiver status codes in TWSR */
#define TW_STATUS					(TWSR & 0xF8) /* Returns value of status register */
#define START_TRANSMITTED			0x08 /* Start condition transmitted */
#define REPEATED_START				0X10 /* Repeated start condition transmitted */
#define SLA_W_TX_ACK				0X18 /* SLA+W transmitted & ACK received */
#define SLA_W_TX_NACK				0X20 /* SLA+W transmitted & NACK received */
#define DATA_TX_ACK					0X28 /* Data byte transmitted & ACK received */
#define DATA_TX_NACK				0X30 /* Data byte transmitted & NACK received */
#define ARBITRATION_LOST_SLA_W		0x38 /* Arbitration lost in SLA+W or data bytes */
#define SLA_R_TX_ACK				0x40 /* SLA+R transmitted & ACK received */
#define SLA_R_TX_NACK				0x48 /* SLA+R transmitted & NACK received */
#define DATA_RX_ACK					0x50 /* Data byte received & ACK returned */
#define DATA_RX_NACK				0x58 /* Data byte received & NACK returned */

/* Function Protypes */
void twiInit();

void twiStart();

void twiStop();

void twiWrite(uint8_t u8data);

uint8_t twiReadACK();

uint8_t twiReadNACK();

uint8_t twiGetStatus();

void twiError();

#endif TWI_H_
