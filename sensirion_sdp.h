#ifndef SENSIRION_SDP_H_
#define SENSIRION_SDP_H_

#include <Arduino.h>

/* SDP 600 address with write bit (0) */
#define SDP_600_ADDR_W   0x80

/* SDP 600 address with read bit (1) */
#define SDP_600_ADDR_R   0x81

/* SDP Command to read differential pressure */
#define SDP_600_READ     0xF1

/* I2C Command to do a soft reset on sensirion sensor */
#define SOFT_RESET       0xFE

// SGM variations and 
typedef enum{
  SDP_500,
  SDP_600,
  PA_25,
  PA_125,
  PA_500,
  ALT_0,
  ALT_250,
  ALT_425,
  ALT_500,
  ALT_750,
  ALT_1500,
  ALT_2250,
  ALT_3000,
};

class SDP
{
  public:
    SDP(uint8_t sensorType);
    void sensirion_reset();
    void sensirion_init();
    uint16_t sensirion_read();
    float get_dp(int rawSensorValue);
   private:
    uint8_t _sensorType;
};

#endif
