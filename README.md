# PID_singlethermo_lcd


# ml_doe_fact
This code was written to PID tune the temperature of a heater for an optical lens.

## 1. Description
This code was written to PID tune the temperature of a heater for an optical lens heater. The intended use was also for temperature tuning electronic components of an electron microscope.

## 2. Necessary libraries

The following libraries are needed to run this script:

#include <PID_v1.h>

#include <SPI.h>

#include "Adafruit_MAX31855.h"

#include <LiquidCrystal.h>

## 3. How it works

1. An arduino uno or suitable microcontroller needs to be wired as described by the [circuit](https://github.com/skchandl/PID_singlethermo_lcd/blob/master/code_circuit/PID_controller_circuit.pdf). 
2. The arduino cannot switch the high power needed for the heater so a MOSFET is used instead. 
3. The feedback temperature is read with a thermocouple wired as described in the circuit.
4. Once running verify each hardware component is working. LCD will display "PID controller" if operating correctly in ` void setup()`.
5. The system can be tuned with the Kp, Ki, and Kd values.











