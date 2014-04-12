/* btDB.h 
 * implements a write efficient database of longs
 * provides push to end, and read from address (defaults to the end)
 * database is int-addressed, and hardware agnostic
 * the driver is defined in btDriver.h 
 */

#ifndef DB_H
#define DB_H

#include "Arduino.h"
#include <btDriver.h>

class DB
{
	public:
		DB (Driver, int = 0);
		void push (long);
		long read (int);
		int getLength();
		int getStart();
	private:
		int mStart, mLength;
		Driver mcMemory;
};

#endif
