// Copyright (C) Sven Rosvall (sven@rosvall.ie)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

// Set up functions for use with CANSHIELD board, i.e. MERG kit 110.
// This board has:
// * MCP2515 CAN Controller
// * Running at 16 MHz
// * Pin assignment:
//   2: Interrupt from the CAN Controller
//   4: VLCB green Uninitialized LED pin
//   7: VLCB yellow Normal LED pin
//   8: VLCB push button switch pin
//  10: SPI CS
//  11: SPI SI
//  12: SPI SO
//  13: SPI SCK

#pragma once

#include <Arduino.h>
#include <LEDUserInterface.h>

#include "CAN2515.h"

namespace VLCB
{
/// @brief Set up functions for the CANSHIELD board.
/// 
/// CANSHIELD (available as MERG kit 110) is a shield for Arduino Uno/Mega/Nano.
/// It contains an on-obard MCP2515 CAN controller.
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
  static byte getGreenLedPin();
  static byte getYellowLedPin();
  static byte getSwitchPin();

  /// Setup LED and switch pins for the LEDUserInterface object.
  static void setupLEDUserInterface(VLCB::LEDUserInterface & ledUserInterface);

  /// Prepare the board and CAN controller for operation.
  bool begin();

  /// Get the underlying CAN2515 objcet
  CAN2515 *getCAN2515();

  
  CAN2515 can2515;
};

}