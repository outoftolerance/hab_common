# HAB Common
This project contains common libraries and code for different parts of the HAB project, things like timing, buffers, accelerometers, message protocols and standards.

# Libraries

## Buffer

## Timer
The Timer library provides basic timing functionaly, this is used to create time-outs for different reasons within the code. It allows the main program loop to run really fast even when there are tasks that might take minutes or even hours without having to wait for these things to complete by using delays (the basic Arduino way). 

This is essentially a primitive way of "multi-threading" on a microcontroller as many tasks can be done "in parallel", i.e. the execution of different elements of different tasks can be done asynchronously.

## Log
The Log library provides a simple interface for event logging withing the program. This allows for easy debugging of the software and provides many useful features such as log levels.

## Data Log
The Data Log librariy provides a way to log complex information to a file on an SD card. This could be telemetry information or other state information that is sensed during the flight of the vehicle. These logs can then be read back post-flight for analysis.

## Telemetry
The Telemetry library provides a level of abstraction from the sensors that are being used to get telemetry information (GPS, IMU, etc) and provides the latest telemetry in an easily digestible manner for higher level applications.

## Simple HDLC
The Simple HDLC (High-level Data Link Control) library provides basic messaging functionaly including message serialization, deserialization, CRC checking, etc. This wraps different byte-wise interfaces (currently implemented only on serial ports) to create a generic message interface.

## Simple Message Protocol
The Simple Message Protocol library (SMP) wraps the SimpleHDLC library at an even higher level, by pre-defining different types of messages and providing encoding and decoding functions for those messages. This library can be thought of as defining a dialect or language between the microcontroller and any other external systems it is messaging with.

## External Libraries
The project also depends on a few externally developed libraries as listed here.

- TinyGPS++
- Adafruit Sensor
- Adafruit 10DOF
- Adafruit BMP085
- Adafruit L3GD20
- Adafruit LSM303DLHC

