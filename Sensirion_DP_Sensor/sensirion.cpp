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
  uint8_t data, status;
  status = TWSR;  
  data = TWDR;
  Serial.print(", 0x"); Serial.print(status, HEX);  
  Serial.print(", MSB:"); Serial.print(data, BIN);  	
}

void printLSB()
{
  uint8_t data, status;
  status = TWSR;
  data = TWDR;
  Serial.print(", 0x"); Serial.print(status, HEX);
  Serial.print(", LSB:"); Serial.print(data, BIN);	
}

int16_t sensirion_read()
{ 
  uint8_t statusCode[7];
  
  /* Send START condition & wait until it goes through */
  twiStart();
  statusCode[0] = TWSR;
  //printTWSRHex();
  
  /* Write the sensor address + write bit & receive ACK */
  twiWrite(SDP_600_ADDR_W);
  statusCode[1] = TWSR;
  //printTWSRHex();
  
  /* Send command to sensor & receive ACK*/
  twiWrite(SDP_600_READ);
  statusCode[2] = TWSR;
  //printTWSRHex();
    
  /* Send repeated START signal */
  twiRepeatStart();
  statusCode[3] =  TWSR;
  //printTWSRHex();

    
  /* Write sensor address + read bit & receive ACK */
  twiWrite(SDP_600_ADDR_R);
  statusCode[4] = TWSR;
  //printTWSRHex();
  
  /* Hold Master */
  	
  
  /* Get MSB of sensor reading & send ACK */
  uint8_t msb = twiGetData();
  statusCode[5] = TWSR;
  //printMSB();
  
  /* Get LSB of sensor reading & send ACK */
  uint8_t lsb = twiGetData();
  statusCode[6] = TWSR; 
  //printLSB();
  
  uint16_t flowReading = ((uint16_t)(msb << 8))|(lsb);
  
  /* Check Byte & send ACK */
  uint8_t checkByte = twiGetData();
  //Serial.print(" Check Byte: "); Serial.println(checkByte);
    
  /* Stop I2C */
  twiStop();
  
  return flowReading;  
}

float get_dp(int rawSensorValue)
{
  return rawSensorValue/60;
}

float get_flow(int rawSensorValue)
{
  return rawSensorValue/327;
}
