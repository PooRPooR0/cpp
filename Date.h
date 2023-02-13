#pragma once
#include <iostream>

class Date
{
protected:
	int day, month, year;
public:
	Date();
	Date(int day);
	Date(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	void set();
	virtual int count();
	int countDaysBetweenDates(Date date1, Date date2);
	Date operator++ ();
	Date operator++ (int);

	friend std::ostream& operator <<(std::ostream& out, const Date& date);
};

Date operator + (Date date1, Date date2);