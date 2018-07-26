# mBed-MissileCommandEmulator
Emulator for a spin-off of the classic arcade game "Missile Command" to be run on the ARM mBed platform.
-------------
##
## File Guide:

	Emulator Files: 
	- game.cpp		=>	main C++ routines
	- globals.h		=>	pushButton interrupts, Collision Checking Mechanism, Alien Generator
	- ship.h/.cpp		=>	Ship Class Interface
	- aliens.h/.cpp	  	=>	Alien Class Interfaces
	
	mBed/Hardware Drivers:
	- mbed/		 	=>	mBed Drivers/Libraries
	- PinDetect/		=>	pushButton Driver
	- 4DGL-uLCD-SE		=> 	4DGL uLCD Drivers
	- MMA8452.h/.cpp	=>	MMA8452 Accelerometer Driver
	- Speaker.h		=> 	Speaker Driver

### NOTE:
- All drivers/libraries are include in globals.h; thus, globals.h is the only file included in game.cpp
