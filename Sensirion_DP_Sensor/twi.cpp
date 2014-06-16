/* 
  ATmega328 I2C functions
  
  TWBR: Selects the division factor for the bit rate generator.
  TWCR: Control register. Controls the operation of the TWI/I2C.
		TWINT - Interrupt flag
		TWEA - Enable acknowledge bit
		TWSTA - Start condition bit
		TWSTO - Stop condition bit
		TWWC - Write collision flag
		TWEN - Enable bit. Enables TWI operation
		TWIE - Interrupt enable bit
  TWDR: Data register which contains the next byte to be transmitted or received
  TWAR: Slave address register
*/
#include "twi.h"

void twiInit()
{
  /* 
  Set SCL to 400kHz 
  TWPS0 and TWPS1 are 0
  
  The SCL Frequency is set by:
  SCL Freq = F_CPU/(16+(2*TWBR*(4^TWPS)))
  */
  TWSR = 0x00; /* Don't need additional prescalers so set to 0x00 */
  TWBR = 0x48; /* Sets SCL to 400KHz */
  
  /* Enable TWI(I2C) */
  TWCR = (1<<TWEN);
}

void twiStart()
{
  /* Generates START signal */
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  
  /* Wait until START condition is transmitted */
  while(!(TWCR & (1<<TWINT)));
  
  /* Check if start transmission successfully transmitted */
  if(START_TRANSMITTED)
	TWCR = (1<<TWINT);
}

void twiStop()
{
  /* Generates STOP signal */
  TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void twiWrite(uint8_t u8data)
{
  /* Write data into data register */
  TWDR = u8data;
  
  /* Wait for transmission to complete */
  while(!(TWCR & (1<<TWINT)));
  
  /* Check for Acknowledge bit */
  if(DATA_TX_ACK)
	/* Clear interrupt flag */
	TWCR = (1<<TWINT)|(1<<TWEN);  
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
  uint8_t twiStatus;
  
  /* mask status */
  twiStatus = TWSR & 0xF8;
  
  return twiStatus;
}

void twiError()
{
  twiStop();
}
