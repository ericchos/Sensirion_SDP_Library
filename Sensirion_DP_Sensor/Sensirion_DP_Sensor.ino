#include "twi.h"
#include "sensirion.h"
#include "port.h"

void setup() 
{
  Serial.begin(115200);
  Serial.print(sizeof(int));
  Serial.print("Sensor Address: "); Serial.println(SDP_600_ADDR_R);
  twiInit();
  
  Serial.print("Flow Reading (dec) "); Serial.println("bin");
}

void loop() 
{  
  int16_t sensorRead = sensirion_read();
  Serial.print(sensorRead,  DEC); Serial.print(", "); Serial.println(sensorRead, BIN);
  delay(1000);
}
