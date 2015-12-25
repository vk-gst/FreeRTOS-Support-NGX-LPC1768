# FreeRTOS-Support-NGX-LPC1768
This project provides the FreeRTOS support for different peripherals on NGX mbed Xpresso Baseboard with LPC 1768


In this project I have implemented the FreeRTOS Board Support Package for NGX Mbed Xpresso Baseboard . 
Controller used : LPC 1768 Xplorer (Stamp) and ported Free RTOS in LPC 1768 Stamp.
H/W Platform: Stamp NGX LPC1768 (ARM cortex M3) Xplorer

The project could be used to access different peripherals in the NGX mbed Xpresso Baseboard.
1. Access LCD, usage of IPC to display messages on LCD.
2. Access EEPROM using I2C protocol for data storage.
3. Basic UART communication.

Import the whole project in LPC Xpresso IDE.

The below is a note from FreeRTOS reference notes:

Board support packages, or BSPs, target the FreeRTOS+IO code to a specific microcontroller, on a specific board. 
It is the equivalent to the port layer found in FreeRTOS itself. 
The FreeRTOS+IO code includes a header file called FreeRTOS_IO_BSP.h. 
This header file should either contain the BSP information directly, or itself just be used to include the BSP header file that is correct for the target being used. 
It is best to locate FreeRTOS_IO_BSP.h in an application directory, along side FreeRTOSIOConfig.h, because the header file is specific to the hardware being used by the application rather than the core FreeRTOS+IO code. 

A BSP includes: 
-- A table that defines the supported peripherals, and how each peripheral is identified in calls to FreeRTOS_open(). 
-- Device specific peripheral drivers. 
-- A set of constants that define peripheral pin outs, LED polarities, etc. 
-- An example FreeRTOSIOConfig.h header file.
-- Documentation that describes any target specific FreeRTOS_ioctl() request codes.

FreeRTOS+IO :
-- It means FreeRTOS+IO is not a part of Free RTOS at all. 
It is a commercial (for sale) package created using Free RTOS API. 
It is layer created between Free RTOS API and peripheral code API (supplied mostly by chip companies). Now why this layer?
It is created so that after porting, same API of FreeRTOS+IO can be used for different boards and even different peripherals.

-- FreeRTOS+IO provides a Linux/POSIX like open (), read (), write (), ioctl () type interface to peripheral driver libraries. 
It sits between a peripheral driver library and a user application to provide a single, common, interface to all supported peripherals across all supported platforms. 
The current board support package implementation(s) support UART, I2C and SPI operation, in both polled and interrupt driven modes.

FreeRTOS+IO API functions: 
-- FreeRTOS_open() : Opens a peripheral for use with FreeRTOS+IO. 
The board support package defines which peripherals are available on any particular platform.

-- FreeRTOS_read() : The board support package defines the peripherals that are available to be opened. 
FreeRTOS_ioctl() is used to select between interrupt driven and polled read modes.

-- FreeRTOS_write() : The board support package defines the peripherals that are available to be opened. 
FreeRTOS_ioctl() is used to select between interrupt driven and polled write modes.

-- FreeRTOS_ioctl() : Ioctl() is the standard name for functions that are used for input output device control, including device specific configuration.
FreeRTOS_ioctl() is the FreeRTOS+IO equivalent. The action to be performed by a call to FreeRTOS_ioctl() is identified by the request code passed into FreeRTOS_ioctl() as the second parameter.

Requirement And Implemented Features:

LPC1768-Xplorer is a CORTEX-M3 based stamp board for NGX’s mbed-Xpresso Baseboard. 
The LPC1768 microcontroller has 512KB of internal flash and 64KB RAM. 
Ethernet MAC, USB Device/Host/OTG interface, 8-channel general purpose DMA controller, 4 UARTs, 2 CAN channels, 2 SSP controllers, SPI interface, 3 I2C-bus interfaces, 2-input plus 2-output I2S-bus interface, 8-channel 12-bit ADC, 10-bit DAC, motor control PWM, Quadrature Encoder interface, 4 general purpose timers, 6-output general purpose PWM, ultra-low power Real-Time Clock (RTC) with separate battery supply, and up to 70 general purpose I/O pins

NGX mbed Xpresso Baseboard mbed-Xpresso BaseBoard and Stamp modules together serve as an excellent platform to evaluate various architectures like ARM7, CORTEX-M3, CORTEX-M0... etc. 
Hardware
-- Dimensions of 115 X 155 mm2
-- Two layer PCB (FR-4 material)

Power
-- Power supply: DC 7.5V with power LED
-- On-board linear regulators generate +3.3V/500mA and +5v/500mA from power supply
-- USB connector ( as alternate power source)

Other Peripherals
-- 256Kb I2C based EEPROM
-- Audio power amplifier with audio jack
-- 2 line X 16 character LCD with back light control
-- Manual program download using serial port (ISP-In System Programming)
