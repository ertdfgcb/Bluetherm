/* BluethermoDriver.h
 * defines the interface for the eeprom driver
 */

#ifndef DRIVER_H
#define DRIVER_H

#include "Arduino.h"
#include <Wire.h>

class Driver
{
	public:
		Driver (int = 0x50);
		void write (unsigned int, byte);
		byte readByte (unsigned int);
		void write (unsigned int, int);
		int readInt (unsigned int);
		void write (unsigned int, long);
		long readLong (unsigned int);
	private:
		int mDeviceAddress;
};

#endif
