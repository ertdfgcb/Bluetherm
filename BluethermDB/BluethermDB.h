/* BluethermDB.h */

#ifndef BLUETHERM_DB_H
#define BLUETHERM_DB_H

#include "Arduino.h"
#include <BluethermDriver.h>

class BluethermDB
{
	public:
		BluethermDB (Driver, int = 0);
		void push (long);
		long read (int);
		int getLength();
		int getStart();
	private:
		int mStart, mLength;
		Driver mcMemory;
};

#endif
