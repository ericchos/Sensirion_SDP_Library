/*
 * Example of reading from sensirion's SDP500/600 series differential pressure sensor
 */
#include <sensirion_sdp.h>

// Create an SDP sensor object
SDP sensor(SDP_600);

uint32_t elapsedTime = 0;

void setup() 
{
  Serial.begin(115200);
  Serial.print("Sensor Address: "); Serial.println(SDP_600_ADDR_R); 
  Serial.print("Flow Reading (dec) "); Serial.println("bin");
  /*
  //Initialize LCD
  lcd.begin(16,2);
  //Print Heading
  lcd.print("Delta P [Pa]: ");
  */
}

void loop() 
{  
  elapsedTime = millis();
  
  uint16_t sensorRead = sensor.sensirion_read();
  float differentialPressure = sensor.get_dp(sensorRead);
  
  Serial.print(elapsedTime); Serial.print(": ");
  Serial.print(sensorRead,  DEC); Serial.print(", "); Serial.println(differentialPressure);
  
  delay(500);
}
