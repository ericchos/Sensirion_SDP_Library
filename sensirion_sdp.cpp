#include "sensirion_sdp.h"
#include "twi.h"

SDP::SDP(uint8_t sensorType)
{
  twiInit();
  _sensorType = sensorType;
}

void SDP::sensirion_reset()
{
  /* Send START condition */
  twiStart();

  /* Send sensor address with write bit */

  /* Receive ACK signal */

  /* Send reset command to sensor */
  twiWrite(SOFT_RESET);

  /* Receive ACK signal */
}

void SDP::sensirion_init(void)
{
  twiStart();
  twiStop();
}

uint16_t SDP::sensirion_read(void)
{
  /* Send START condition & wait until it goes through */
  twiStart();

  /* Write the sensor address to write command */
  twiWrite(SDP_600_ADDR_W);

  /* Get Acknowledge bit */

  /* Send command to sensor */
  twiWrite(SDP_600_READ);

  /* Get Acknowledge bit */

  /* Send a repeated START signal */
  twiStart();

  /* Write sensor address to read */
  twiWrite(SDP_600_ADDR_R);

  /* Hold Master */

  /* Get MSB of sensor reading */
  uint8_t flowReadingMSB = twiReadAck();

  /* Get LSB of sensor reading */
  uint8_t flowReadingLSB = twiReadAck();

  /* Get CRC Byte */
  uint8_t crcByte = twiReadAck();

  /* Stop I2C */
  twiStop();

  /* Process the received data */
  int16_t flowReading = ((uint16_t)flowReadingMSB << 8) | flowReadingLSB;

  return flowReading;
}

float SDP::get_dp(int rawSensorValue)
{
  return (float)rawSensorValue/ 60;
}
