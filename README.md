Sensirion_SDP_Library
===================

Sensirion's SDP series differential pressure sensor measures differential pressure in air. 
This sensor has many good uses such as measuring air flow or monitoring an air filter to track when to change it.

More information can be found on Sensirion's website:
https://www.sensirion.com/en/flow-sensors/differential-pressure-sensors/digital-differential-pressure-sensors-without-zero-point-drift/

Also, a direct link to the datasheet can be found here:
https://www.mouser.com/datasheet/2/682/Sensirion_Differential_Pressure_Sensors_SDP600Seri-1109144.pdf

## This is an Arduino Library to use the Sensirion SDP series sensors. 

Sensirion SDP sensors uses I2C and runs off 3.3V so be sure to use a 5V to 3.3V level shifter.

To use:
1. Clone this repository to your **Arduino/libraries** folder and restart arduino to use.
2. To include the library to your sketch add `#include <sensirion_sdp.h>` to the top of your sketch

Features:
1. Measure differential pressure in *Pa* for the SDP500 and SDP600.

Future Work:
1. Add capability for Sensirion's new SDP800 series sensors.

Enjoy and please feel free to leave a comment if help is needed to set up the library or to report any issues.
