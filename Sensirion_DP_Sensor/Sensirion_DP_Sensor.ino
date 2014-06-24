#include "twi.h"
#include "sensirion.h"
#include "port.h"

void setup() 
{
  Serial.begin(115200);
  Serial.print("Sensor Address: "); Serial.println(SDP_600_ADDR_R);
  
  /* Initialize I2C hardware for the sensor */
  twiInit();
  
  Serial.print("Flow Reading (dec) "); Serial.println("bin");
}

void loop() 
{  
  int rawVal = sensirion_read();
  float sensorRead = get_dp(rawVal);
  //Serial.print(rawVal,  DEC); Serial.print(", "); Serial.println(rawVal, BIN);
  Serial.print("Raw: "); Serial.print(rawVal);
  Serial.print(" Actual Val: "); Serial.println(sensorRead);
  delay(500);
}
