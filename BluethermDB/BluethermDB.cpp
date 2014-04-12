#include "BluethermDB.h"

BluethermDB::BluethermDB (Driver *device, int start)
{
	mcMemory = device;
	mStart = mLength = start;
}

void BluethermDB::push (long value)
{
	mcMemory->write (mLength, value);
	mLength++;
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
