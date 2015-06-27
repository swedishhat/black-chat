Black-Chat Discrete RF Transceiver
==================================

Wireless Communication Tool by Russell Crowe & Patrick Lloyd

###Premise:
In many situations it is necessary to sent text communication and transfer files discretely between two computers. With the recent exposure of warrantless government wiretapping protecting one's privacy more difficult than ever. The purpose of BlackChat is to create a secure, discrete, and plausibly deniable point-to-point communication system for text and eventually files between two or more computers. This project was created as a BSEE senior design project for University of Florida in 2014.

###Features
* 433 MHz operation
  * ASK protocol based on [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire/)
  * Superregenerative receiver made entirely of discrete components
* Operating system agnostic
  * Uses FT232 USB UART device to communicate between PC and transceiver
  * Can be accessed through Screen, Putty, Minicom, and any other COM port interface software

###Warnings
This project was purely educational and never intended to comply with FCC regulations on radio emissions. 433 MHz was selected due to it's use in ISM applications but beyond that, your mileage may vary.

###Work In Progress
This project was originally designed in Altium Designer 13/14 but is now being overhauled to work in Kicad to promote a more open-source mentality. The C code will also be rewritten for clarity and probably re-implemented with a custom port of the [Airspayce RadioHead](http://www.airspayce.com/mikem/arduino/RadioHead/) library since that superceded VirtualWire. Also, it would be very cool if this could be expanded to data and filesharing in the future.