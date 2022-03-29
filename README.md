# ELEKTRONIKA-1 - A replacement module for a USSR made vintage LED watch anno 1978

## It actually works
The watch works very well and I am very happy with it.

It has been my daily driver for a few months by now with no problems what so ever.

It can show time, date and year which was more or less what you got in the original.

The module is based around:
* Texas Instruments MSP430fr2433 micro controller
* Austria Micro Systems AS1115 64 bit LED driver
* Vintage Hewlett Packard HP-5082-7414 4x7 segments + dot display
* CR2032 battery

## Source code
All functions are placed own modules and consists of:

* buttons.c - This is the button driver and it handles button events 
* clocksystem.c - Initializes the clock system in the MSP430
* config.h - Global timing and clock constants
* debounce.c - The button debounce detection and filtering using a sliding bit buffer
* display.c - Display update functions like content and intensity.
* driverlib_ng.c - My overloading of the TI MSP430 driver lib for better pin handling
* elektronika.c - Handles the control flow of everything
* render.c - Simple 7 segment 'font' driver
* rtcclock.c - Realtime clock module supporting adjusting date and time
* utils.h - Macros for entering and exiting critical sections

Written using Code Composer Studio.

## Hardware

The PCB is designed in KiCad and is my first ever multi layer PCB.

Button contacts are made with what would normally be plated half castellated holes but they are in reality nothing more than partially routed mounting holes.

The AS1115 display driver was choosen as it is able to drive the LED display directly as well as adjusting the current.

A lot of care has been taken to save as much power as possible.  Battery life is messured to be around 10 years (less if you actually press buttons as the LED technology from the late 1970 uses a lot of current).

The watch uses around 0.002 mA/h in standby and 10-40 mA/h while the display is on.

Originally the two 1.55 V batteries didn't even last a year.

Schematics:

![Schematics](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/Schematics.png)

The four PCB layers:

![The four PCB layers](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/PCB-Front.png)

3D render of front PCB:

![3D render of front PCB](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/PCB-Front-3D.png)

3D render of back PCB:

![3D render of back PCB](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/PCB-Back-3D.png)

What the original module looks like:

![Original module](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/module.jpg)

Showing time:

![Showing time](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/Watch-1.jpg)

Showning date:

![Showning date](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/Watch-2.jpg)

On wrist:

![On wrist](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/Watch-3.jpg)

Dissambled:

![Dissambled](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/Watch-4.jpg)

New watch module:

![New watch module](https://github.com/BenjaminSoelberg/elektronika-1/blob/main/Watch-5.jpg)
