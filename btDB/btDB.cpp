#include "BluethermoDB.h"

DB::DB (Driver device, int start)
{
	mcMemory = device;
	mStart = mLength = start;
}

void DB::push (long value)
{
	mcMemory.write (mLength, value);
	mLength++;
}

long DB::read (int address)
{
	return mcMemory.readLong (address);
}

int DB::getLength()
{
	return mLength;
}

int DB::getStart()
{
	return mStart;
}
