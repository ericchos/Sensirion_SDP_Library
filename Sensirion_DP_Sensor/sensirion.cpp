#include "sensirion.h"

void sensirion_reset()
{
  /* Send START condition */
  twiStart();
  
  /* Send sensor address with write bit */
  
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

int16_t sensirion_read()
{ 
  uint8_t status;
  /* Send START condition & wait until it goes through */
  twiStart();
  status = TWSR; 
  Serial.print("1. Status: "); Serial.println(status, HEX);
  
  /* Write the sensor address to write command */
  twiWrite(SDP_600_ADDR_W);
  
  /* Get Acknowledge bit */
  //while(!twiReadACK());
  status = TWSR;
  Serial.print("2. Status: "); Serial.println(status, HEX);  
  
  /* Send command to sensor */
  twiWrite(SDP_600_READ);

  /* Get Acknowledge bit */
  status = TWSR;
  Serial.print("3. Status: "); Serial.println(status, HEX);
    
  /* Send START signal */
  twiStart();
  status = TWSR;
  Serial.print("4. Status: "); Serial.println(status, HEX);
    
  /* Write sensor address to read */
  twiWrite(SDP_600_ADDR_R);
  
  /* Get acknowledge bit */
  status = TWSR;
  Serial.print("5. Status: "); Serial.println(status, HEX);  
  
  /* Hold Master */
  status = TWSR;
  Serial.print("6. Status: "); Serial.println(status, HEX);
  
  /* Get MSB of sensor reading */
  unsigned char flowReadingMSB = TWDR;
  Serial.print("MSB: "); Serial.println(flowReadingMSB, BIN);
  
  /* Send an acknowledge bit */
  //while(!twiReadACK());
  twiWrite(0x01);
  status = TWSR;
  Serial.print("7. Status: "); Serial.println(status, HEX);
  
  /* Get LSB of sensor reading */
  unsigned char flowReadingLSB = TWDR;
  Serial.print("LSB: "); Serial.println(flowReadingLSB, BIN);
  
  /* Send an acknowledge bit */
  twiWrite(0x01);
  status = TWSR;
  Serial.print("8. Status: "); Serial.println(status, HEX);
  
  int16_t flowReading = (flowReadingMSB >> 8)|flowReadingLSB;
  
  /* Check Byte */
  status = TWSR;
  Serial.print("9. Status: "); Serial.println(status, HEX);
    
  /* Send an acknowledge bit */
  twiWrite(0x01);
  status = TWSR;
  Serial.print("10. Status: "); Serial.println(status, HEX);
    
  /* Stop I2C */
  twiStop();
  
  return flowReading;  
}

float get_dp(int rawSensorValue)
{
  return rawSensorValue/60;
}
