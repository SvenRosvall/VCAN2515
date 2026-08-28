<img align="right" src="ArduinoVLCB.png"  width="150" height="75">

# VCAN2515

This repository implements the CAN transport support for the MCP2515 CAN 
tranceiver for use with the [VLCB-Arduino](https://github.com/SvenRosvall/VLCB-Arduino).

## Examples

There are a few example sketches in the `examples` directory. 
They are similar to the example sketches in the VLCB-Arduino library but 
using this CAN2515 CAN transport instead of the serial transport.

See more details in [Examples Documentation](docs/Examples.md).

## Supported platforms

This library has been tested with Arduino Nano and Raspberry Pi Pico boards.

It has also been compiled successfully for the ESP32 platform.

## Dependencies
Note that this library depends on a number of other libraries which must also be downloaded and included in the sketch:

* [VLCB](https://github.com/SvenRosvall/VLCB-Arduino) - The core VLCB library
* [ACAN2515](https://github.com/pierremolinaro/acan2515) - CAN bus transport using the MCP2515 controller
* [Streaming](https://github.com/janelia-arduino/Streaming) - C++ style output
