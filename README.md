# LisaKeysPlus
This repository contains a project to create a modern replacement PCB for Apple Lisa keyboards.

The Apple Lisa used a Keytronic foam and foil keyboard which is notorious for the foam turning to dust rendering the keyboard unusable. Even after replacing the foam, I was unable to get my Lisa keyboard fully working, so instead I created a replacement PCB so I could use modern keyswitches.

This repository is still a work in progress. The timing on the keyboard controller code still needs adjusting, and the PCB may require further revisions. For example, I only recently added stabilizers to the board. If you downloaded the PCB designs before 28 November 2023, you will want to download them again to get stabilizers and a better fitting PCB. Otherwise your keys won't be stable and you'll need to expand some of the holes with a Dremel.

## Stuff To Get
* 76x Cherry MX compatible keyswitches
* 76x through-hole 1N4148 diodes
* 1x through-hole 3mm LED
* 1x through-hole 150 ohm resistor
* 2x through-hole 3-pin 2.54mm-spacing male headers
* 2x through-hole 14-pin 2.54mm-spacing male headers
* 1x through-hole 5-pin 2.54mm-spacing male header
* 1x Adafruit ItsyBitsy 32u4 5V microcontroller
* 1x 2-pin jumper
* 6x 2u stabilizers
* 1x 6.5u stabilizer (good luck; you will most likely need to get a 7u stabilizer and shorten it)

## Stuff to Make
* 1x keyboard matrix PCB, made from the Gerber files in the `gerber` directory
* 4x mounting brackets, 3D printed from the STL file in the `mounting-bracket` directory
* a set of keycaps, made from the templates in the `keycaps` directory (more details below)

## Stuff to Do
* Program the ItsyBitsy microcontroller with the Arduino sketch in the `lisakeysplus` directory
* Solder in the diodes **first**
* Solder in the LED in the desired location near the caps lock key
* Solder in the resistor and headers
* Solder in the ItsyBitsy microcontroller
* Solder in the keyswitches **last**
* Add the jumper between VCC and TIP on the header above the microcontroller
* Attach the stabilizers
* Install the keycaps
* Install the four mounting brackets in the bottom of the keyboard case
* Attach the keyboard cable to the header on the top left of the board
* Assemble the keyboard case
