# Example Sketches
A few example sketches are included in the `examples` directory.
These illustrate how this library can be used.

They are similar to the [Example Sketches in the VLCB-Arduino](https://github.com/SvenRosvall/VLCB-Arduino/blob/main/docs/Examples.md)
but use the CAN2515 CAN transport instead of the serial transport.

## Common structure
All the example sketches have a structure that defines all the necessary
elements in order.

* Header files for types used in the sketch.
* definitions of module ID and version. Also defining pins for mode push button and LEDs.
* Define objects to use in the module. 
  The key object here is the controller which is the key functional point in the VLCB library.
* Module name. 
* Function setupVLCB() configures all the parameters for VLCB.
* Function setup() is used in all Arduino sketches to set up things.
  Here it is used to call setupVLCB() and any module specific setup.
* Function loop() is used in all Arduino sketches to run the Arduino.
  Here it runs the controller object to process any VLCB messages coming in and out.
  It also runs any module specific code.

## [VLCB_empty](../examples/VLCB_empty/VLCB_empty.ino)
A bare minimum sketch that only contains the necessary services 
(```MinimumNodeServiceWithDiagnostics``` and ```CANServiceWithDiagnostics```). 
It can be used to demonstrate that the Arduino module can communicate with CAN bus
and can communicate with FCU.
The FCU can assign a node number and query the module parameters.

The services used in this sketch have enabled diagnostics so that all
features of VLCB can be demonstrated.

Note that there are no support for node variables or events.

## [VLCB_1in1out](../examples/VLCB_1in1out/VLCB_1in1out.ino)
A small module that uses one input for producing events and one output that
is controlled by consumed events. 
For this it uses NodeVariableService and four services for event support.

The sketch defines one `moduleSwitch` object for an input pin 
and one `moduleLED` object for an output pin.

To manage these two I/O pins there are two functions:
* processModuleSwitchChange() queries the moduleSwitch and sends an event.
* eventhandler() is called for incoming events and controls the moduleLED.

There are two event variables:

| EV# | Function                                                                                  |
|-----|-------------------------------------------------------------------------------------------|
| 1   | Input channel number. Set to 1 to send this event when the moduleSwitch is changed        |
| 2   | Output function. Set to 1 to turn on the moduleLED. Set to 2 to make the moduleLED blink. |

The sketch supports self-consumed events. 
Create an event with EV#1 set to 1 to react to the moduleSwitch. 
Set EV#2 to make moduleLED change.
Now the LED will react when the switch is changed.

If the moduleSwitch is changed but there is no stored event with EV#1 == 1
then no event is produced.

This sketch uses services with diagnostics enabled to demonstrate them.

## [VLCB_CANSHIELD_1in1out](../examples/VLCB_CANSHIELD_1in1out/VLCB_CANSHIELD_1in1out.ino)
This is similar to the [VLCB_1in1out](#vlcb_1in1out) sketch above but makes
use of the board definition class [CANSHIELD](../src/CANSHIELD.h) to simplify
the sketch to set up all the pins and other board specific things for the
CANSHIELD board (a.k.a. MERG kit 110). 
This board is an Arduino shield for Arduino Uno, Nano and Mega and
provides a MCP2515 controller and the CBUS mode LEDs and push button.

## [VLCB_Pico_1in1out](../examples/VLCB_Pico_1in1out/VLCB_Pico_1in1out.ino)
This is similar to the [VLCB_1in1out](#vlcb_1in1out) sketch above but makes
use of the board definition class [PicoCANBus](../src/PicoCANBus.h) to simplify
the sketch to set up all the pins and other board specific things for the
Pico CAN Bus board developed by Duncan Greenwood. 
This board is a carrier board for Raspberry Pi Pico controllers and 
provides a MCP2515 controller and the CBUS mode LEDs and push button. 

## [VLCB_4in4out](../examples/VLCB_4in4out/VLCB_4in4out.ino)
This is a larger sketch that handles 4 input pins and 4 output pins.
See full documentation for this sketch in its own [README](../docs/VLCB4in4out_README.md).

This sketch does not enable diagnostics to save memory on small processors
and also to demonstrate that diagnostics is optional.

## [VLCB_4in4out_slot](../examples/VLCB_4in4out_slot/VLCB_4in4out_slot.ino)
This sketch has a similar functionality to ```VLCB_4in4out``` above but
is implemented using "event slots" instead of relying on specific event variables.

Events in slots 1-4 are produced when switch 1-4 respectively is activated.
If there is no event in the slot for an activated switch then a
default event is created.

Consumed events in slots 10-19 activate LED 1,
events in slots 20-29 activate LED 2, etc.

## [VLCB_long_message_example](../examples/VLCB_long_message_example/VLCB_long_message_example.ino)
This is an example sketch that makes use of long messages.

Unfortunately long messages in this library have not been
tested properly and follow the RFC0005 draft rather than
the VLCB Long Messages Service specification.
