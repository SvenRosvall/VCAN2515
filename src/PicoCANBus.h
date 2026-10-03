// Copyright (C) Sven Rosvall (sven@rosvall.ie)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#pragma once

#include <Arduino.h>
#include <LEDUserInterface.h>

#include "CAN2515.h"

namespace VLCB
{
/// @brief Set up functions for the Pico CAN Bus board.
/// 
/// RPi Pico CAN Bus board created by Duncan Greenwood to provide CBUS connection for a RPi Pico.
/// It contains an on-obard MCP2515 CAN controller and CBUS LEDs and push button.
/// This class contains functions for setting up SPI pins, oscillator frequency, 
/// CBUS LEDs and pushbutton pins.
/// 
/// This board has:
/// * MCP2515 CAN Controller
/// * Running at 16 MHz
/// * Pin assignment:
///   1: Interrupt from the CAN Controller
///   2: SCK0
///   3: MOSI0
///   4: MISO0
///   5: CAN CS
///   21: VLCB green Uninitialized LED pin
///   29: VLCB yellow Normal LED pin
///   22: VLCB push button switch pin
class PicoCANBus
{
public:
  static byte getGreenLedPin();
  static byte getYellowLedPin();
  static byte getSwitchPin();

  /// Setup LED and switch pins for the LEDUserInterface object.
  static void setupLEDUserInterface(VLCB::LEDUserInterface & ledUserInterface);

  /// Prepare the board and CAN controller for operation.
  bool begin();

  /// Get the underlying CAN2515 object
  CAN2515 *getCAN2515();

  /// The underlying CAN2515 transport object.
  CAN2515 can2515;
};

}