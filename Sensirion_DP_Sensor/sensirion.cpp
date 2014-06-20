#include "sensirion.h"

void sensirion_reset()
{
  /* Send START condition */
  twiStart();
  
  /* Send sensor address with write bit */
  twiWrite(SDP_600_ADDR_W);
  
  /* Receive ACK signal */
  
  /* Send reset command to sensor */
  twiWrite(SOFT_RESET);
  
  /* Receive ACK signal */
}

void sensirion_init()
{
  twiStart();
  twiStop();
}

void printTWSRHex()
{
  uint8_t status;
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);
}

void printMSB()
{
  uint8_t data;
  data = TWDR;
  Serial.print(", MSB:"); Serial.print(data, BIN);  	
}

void printLSB()
{
  uint8_t data;
  data = TWDR;
  Serial.print(", LSB:"); Serial.print(data, BIN);	
}

int16_t sensirion_read()
{ 
  uint8_t status;
  
  /* Send START condition & wait until it goes through */
  twiStart();
  status = TWSR; 
  Serial.print("0x"); Serial.print(status, HEX);
  
  /* Write the sensor address to write command */
  twiWrite(SDP_600_ADDR_W);
  
  /* Get Acknowledge bit */
  //while(!twiReadACK());
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);  
  
  /* Send command to sensor */
  twiWrite(SDP_600_READ);

  /* Get Acknowledge bit */
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);
    
  /* Send START signal */
  twiStart();
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);
    
  /* Write sensor address to read */
  twiWrite(SDP_600_ADDR_R);
  
  /* Get acknowledge bit */
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);  
  
  /* Hold Master */
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);
  
  /* Get MSB of sensor reading */
  unsigned char flowReadingMSB = TWDR;
  Serial.print(", MSB: "); Serial.print(flowReadingMSB, BIN);
  
  /* Send an acknowledge bit */
  //while(!twiReadACK());
  twiWrite(0x01);
  //while(!(TWCR & (1<<TWINT)));  
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);
  
  /* Get LSB of sensor reading */
  unsigned char flowReadingLSB = TWDR;
  Serial.print(", LSB: "); Serial.print(flowReadingLSB, BIN);
  
  /* Send an acknowledge bit */
  twiWrite(0x01);
  //while(!(TWCR & (1<<TWINT)));
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);
  
  int16_t flowReading = ((unsigned int)(flowReadingMSB << 8))|((unsigned char)flowReadingLSB);
  
  /* Check Byte */
  while(!(TWCR & (1<<TWINT)));
  status = TWSR;
  Serial.print(", 0x"); Serial.print(status, HEX);
    
  /* Send an acknowledge bit */
  twiWrite(0x01);
  //while(!(TWCR & (1<<TWINT)));
  status = TWSR;
  Serial.print(", 0x"); Serial.println(status, HEX);
    
  /* Stop I2C */
  twiStop();
  
  return flowReading;  
}

float get_dp(int rawSensorValue)
{
  return rawSensorValue/60;
}
