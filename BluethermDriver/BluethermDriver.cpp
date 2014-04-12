/* BluethermoDriver.cpp
 * implements memory interface
 * provides read/write byte, int, and long functions 
 * all hardware specific code is in read and write byte
 * therefore to adapt to a new device all that needs to be written are a read 
 * 	and write byte function.
 */

#include "btDriver.h"

Driver::Driver (int deviceAddress)
{
	deviceAddress = deviceAddress;
	Wire.begin();
}

/* read and write for bytes
 * implements writes to this device:
 * https://www.sparkfun.com/products/525
 * the protocol for which is:
 * 1. send most significant byte of address
 * 2. send least significant byte of address
 * 3/write: send data byte
 * 3/read: read data byte
 */
void Driver::write (unsigned int address, byte data)
{
	Wire.beginTransmission (mDeviceAddress);
	Wire.write ((int)(address >> 8));
	Wire.write ((int)(address & 0xFF));
	Wire.write (data);
	Wire.endTransmission();
}

byte Driver::readByte (unsigned int address)
{
	byte data = 0xFF;
	Wire.beginTransmission (mDeviceAddress);
	Wire.write ((int)(address >> 8));
	Wire.write ((int)(address & 0xFF));
	Wire.endTransmission ();
	Wire.requestFrom(mDeviceAddress, 2);
	if (Wire.available ())
	{
		data = Wire.read ();
	}
	return data;
}

/* read and write for ints
 * based upon the read and write functions for bytes
 */
void Driver::write (unsigned int address, int data)
{
	        write(address, (byte)(data >> 0));
	        write(address++, (byte)(data));
}

int Driver::readInt (unsigned int address)
{
		byte mostSigByte = readByte(address);
		byte leastSigByte = readByte (address++);
		int data = (int(mostSigByte) << 8) | leastSigByte;
		return data;
}

/* read and write for longs
 * based upon the read and write functions for ints
 */
void Driver::write (unsigned int address, long data)
{
	        write (address, (int)(data >> 16));
		write (address + 2, (int)(data));
}

long Driver::readLong (unsigned int address)
{
	        int mostSigInt = readInt (address);
		int leastSigInt = readInt (address + 2);
		long data = (int(mostSigInt) << 16) | leastSigInt;
		return data;
}
