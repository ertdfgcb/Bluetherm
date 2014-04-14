#include "BluethermDB.h"

BluethermDB::BluethermDB (Driver *device, int start)
{
	mcMemory = device;
	mStart = m = start;
}

void BluethermDB::push (long value)
{
	mLength++;
	mcMemory->write (mLength, value);
}

long BluethermDB::read (int address)
{
	return mcMemory->readLong (address);
}

int BluethermDB::getLength()
{
	return mLength;
}

int BluethermDB::getStart()
{
	return mStart;
}
