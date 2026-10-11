// Copyright (C) Sven Rosvall (sven@rosvall.ie)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#include "CANSHIELD.h"

namespace VLCB
{
// Pin assignments on the board.
static const byte LED_GRN = 4;             // VLCB green Unitialised LED pin
static const byte LED_YLW = 7;             // VLCB yellow Normal LED pin
static const byte SWITCH0 = 8;             // VLCB push button switch pin

byte CANSHIELD::getGreenLedPin()
{
  return LED_GRN;
}

byte CANSHIELD::getYellowLedPin()
{
  return LED_YLW;
}

byte CANSHIELD::getSwitchPin()
{
  return SWITCH0;
}

void CANSHIELD::setupLEDUserInterface(VLCB::LEDUserInterface &ledUserInterface)
{
  ledUserInterface.setGreenLedPin(getGreenLedPin());
  ledUserInterface.setYellowLedPin(getYellowLedPin());
  ledUserInterface.setSwitchPin(getSwitchPin());
}

bool CANSHIELD::begin()
{
  can2515.setOscFreq(16000000UL);   // select the crystal frequency of the CAN module
#ifndef ARDUINO_ARCH_RP2040
  // CAN for RP2040 sets more pins.
  can2515.setPins(10, 2);           // select pins for CAN bus CE and interrupt connections
#endif
  return can2515.begin();
}

bool CANSHIELD::hasCanErrors()
{
  return can2515.errorStatus() != 0;
}

}
