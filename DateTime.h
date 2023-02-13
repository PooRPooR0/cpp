#pragma once
#include "Date.h"
#include <iostream>

class DateTime : protected Date
{
private:
	int hour;
	int minute;
	int secund;
public:
	DateTime();
	DateTime(int hour, int day);
	DateTime(int hour, int minute, int secund, int day, int month, int year);
	int getHour();
	int getMinute();
	int getSecund();
	int setHour(int nHour);
	int setMinute(int nMinute);
	int setSecund(int nSecund);
	void set();
	virtual int count();

	friend std::ostream& operator <<(std::ostream& out, const DateTime& datetime);
	DateTime operator=(Date date);
};
