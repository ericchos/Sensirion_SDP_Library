#include <LiquidCrystal.h>
#include "twi.h"
#include "sensirion.h"

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() 
{
  Serial.begin(115200);
  Serial.print(F("Sensor Address: ")); Serial.println(SDP_600_ADDR_R);
  
  /* Initialize I2C hardware for the sensor */
  twiInit();
  
  Serial.print(F("Flow Reading (dec) ")); Serial.println("bin");
  
  //Initialize LCD
  lcd.begin(16,2);
  //Print Heading
  lcd.print("Delta P [Pa]: ");  
}

void loop() 
{
  uint32_t time = millis();  
  int16_t rawVal = sensirion_read();
  
  //float sensorRead = get_dp(rawVal);
  float sensorRead = get_dp(rawVal);
  Serial.print(time); 
  Serial.print(", ");
  Serial.print(rawVal); 
  Serial.print(", "); 
  Serial.print(sensorRead);
  
  lcd.setCursor(0, 1);
  lcd.print("                ");
  
  lcd.setCursor(0, 1);
  lcd.print(sensorRead);
  delay(500);
}
