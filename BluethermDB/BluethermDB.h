/* BluethermDB.h */

#ifndef BLUETHERM_DB_H
#define BLUETHERM_DB_H

#include "Arduino.h"
#include <BluethermDriver.h>

class BluethermDB
{
	public:
		BluethermDB (Driver*, int = 0);
		void push (long);
		long pop (int = mEnd);
		int getLength();
		int getStart();
	private:
		int mStart, mEnd
		Driver *mcMemory;
};

#endif
