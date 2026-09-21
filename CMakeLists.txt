cmake_minimum_required(VERSION 4.2)
project(VCAN2515)

set(CMAKE_CXX_STANDARD 11)

include_directories(Arduino)
include_directories(src)

# Include files from main VLCB project.
# Assumes it is checked out in a sibling directory.
# Using path to working directory instead of pulling from Git in case there are local changes.
include_directories(../VLCB-Arduino/Arduino)
include_directories(../VLCB-Arduino/src)

add_library(VCAN2515 OBJECT
        src/CAN2515.cpp
        src/CAN2515.h

        src/CANSHIELD.cpp
        src/CANSHIELD.h

        Arduino/ACAN2515.h

        examples/VLCB_1in1out/VLCB_1in1out.ino
        examples/VLCB_4in4out/VLCB_4in4out.ino
        examples/VLCB_4in4out_slot/VLCB_4in4out_slot.ino
        examples/VLCB_empty/VLCB_empty.ino
        examples/VLCB_long_message_example/VLCB_long_message_example.ino
)
