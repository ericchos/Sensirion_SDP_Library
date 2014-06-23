/* 
  ATmega328 I2C functions
  
  TWBR: Selects the division factor for the bit rate generator.
  
  TWCR: Control register. Controls the operation of the TWI/I2C.
	[TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|----|TWIE]
		TWINT - Interrupt flag
		TWEA - Enable acknowledge bit
		TWSTA - Start condition bit
		TWSTO - Stop condition bit
		TWWC - Write collision flag
		TWEN - Enable bit. Enables TWI operation
		TWIE - Interrupt enable bit

  TWSR: TWI Status Register
  [TWS
  
  TWDR: Data register which contains the next byte to be transmitted or received
  
  TWAR: Slave address register
*/
#include "twi.h"

void twiInit()
{
  /* The SCL Frequency is set by:
	 SCL Freq = F_CPU/(16+(2*TWBR*(4^TWPS))) */
  
  TWSR = 0x00; /* Don't need additional prescalers so set to 0x00 */
  TWBR = TWI_BIT_RATE; /* Sets SCL Frequency */
  
  /* Enable TWI(I2C) */
  TWCR = (1<<TWEN);
}

void twiStart()
{
  /* Generates START signal */
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  
  /* Wait until START condition is transmitted */
  while(!(TWCR & (1<<TWINT)));
  
  /* Check if Start condition is transmitted */
}

void twiStop()
{
  /* Generates STOP signal */
  TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
  
  /* Wait for STOP signal to transmit */
  while(!(TWCR & (1<<TWSTO)));
}

void twiWriteAddr(uint8_t u8address)
{  
  /* Load I2C slave address into TWDR */
  TWDR = u8address;	
  
  /* Initiate send */
  TWCR = (1<<TWINT)|(1<<TWEN);
  
  /* Wait for command to go through */
  while(!(TWCR & (1<<TWINT)));
  
  /* Check if address is sent & ACK bit received */
}

void twiWrite(uint8_t u8data)
{
  /* Write data into data register */
  TWDR = u8data;
  
  /* Clear TWI interrupt flag & enable TWI */
  TWCR = (1<<TWINT)|(1<<TWEN);
  
  /* Wait for transmission to complete */
  while(!(TWCR & (1<<TWINT)));
  
  /* Check if data is sent & ACK bit received */
  
}

uint8_t twiReadACK()
{
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
  
  while(!(TWCR & (1<<TWINT)));
  
  return TWDR;
}

uint8_t twiReadNACK()
{
  TWCR = (1<<TWINT)|(1<<TWEN);
  
  while(!(TWCR & (1<<TWINT)));
  
  return TWDR;
}

uint8_t twiGetStatus()
{  
  /* mask status */
  uint8_t twiStatus = TWSR & 0xF8;
  
  return twiStatus;
}

void twiError()
{
  twiStop();
}

uint8_t twiGetData()
{
  /* */
  TWCR = (1<<TWINT)|(1<<TWEA);
  
  /* Wait for transmission to complete */
  while(!(TWCR & (1<<TWINT)));
  
  /* Load byte TWDR register value into twiByte */
  uint8_t twiByte = TWDR;
  
  return twiByte;	
}