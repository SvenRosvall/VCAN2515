// Copyright (C) Sven Rosvall (sven@rosvall.ie)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#include "PicoCANBus.h"

namespace VLCB
{
// Pin assignments on the board.
static const byte LED_GRN = 21;             // VLCB green Unitialised LED pin
static const byte LED_YLW = 20;             // VLCB yellow Normal LED pin
static const byte SWITCH0 = 22;             // VLCB push button switch pin

byte PicoCANBus::getGreenLedPin()
{
  return LED_GRN;
}

byte PicoCANBus::getYellowLedPin()
{
  return LED_YLW;
}

byte PicoCANBus::getSwitchPin()
{
  return SWITCH0;
}

void PicoCANBus::setupLEDUserInterface(VLCB::LEDUserInterface &ledUserInterface)
{
  ledUserInterface.setGreenLedPin(getGreenLedPin());
  ledUserInterface.setYellowLedPin(getYellowLedPin());
  ledUserInterface.setSwitchPin(getSwitchPin());
}

bool PicoCANBus::begin()
{
  can2515.setOscFreq(16000000UL);   // select the crystal frequency of the CAN module
  can2515.setPins(5, 1, 3, 4, 2);           // select pins for CAN bus CE and interrupt connections
  return can2515.begin();
}

CAN2515 *PicoCANBus::getCAN2515()
{
  return &can2515;
}

}
