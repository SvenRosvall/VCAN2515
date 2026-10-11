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
/// @brief Set up functions for the CANSHIELD board.
/// 
/// CANSHIELD (available as MERG kit 110) is a shield for Arduino Uno/Mega/Nano.
/// It contains an on-obard MCP2515 CAN controller and CBUS LEDs and push button.
/// This class contains functions for setting up SPI pins, oscillator frequency, 
/// CBUS LEDs and pushbutton pins.
/// 
/// This board has:
/// * MCP2515 CAN Controller
/// * Running at 16 MHz
/// * Pin assignment:
///   2: Interrupt from the CAN Controller
///   4: VLCB green Uninitialized LED pin
///   7: VLCB yellow Normal LED pin
///   8: VLCB push button switch pin
///  10: SPI CS
///  11: SPI SI
///  12: SPI SO
///  13: SPI SCK
class CANSHIELD
{
public:
#ifdef ARDUINO_ARCH_RP2040
  // If this is an RPi Pico then this file shall be compilable but this class shall not be instantiatable and will not compile if used anyway.
  CANSHIELD() = delete;
#endif
  
  static byte getGreenLedPin();
  static byte getYellowLedPin();
  static byte getSwitchPin();

  /// Setup LED and switch pins for the LEDUserInterface object.
  static void setupLEDUserInterface(VLCB::LEDUserInterface & ledUserInterface);

  /// Prepare the board and CAN controller for operation.
  bool begin();

  /// Get the underlying CAN object
  CanTransport *getCanTransport()
  {
    return &can2515;
  }
  
  /// Get the underlying CAN2515 object
  CAN2515 *getCAN2515()
  {
    return &can2515;
  }

  bool hasCanErrors();

  /// The underlying CAN2515 transport object.
  CAN2515 can2515;
};

}