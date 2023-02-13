#include "DateTime.h"
#include <iostream>
#include <string>

using namespace std;

DateTime::DateTime() : Date() {
	hour = 0;
	minute = 0;
	secund = 0;
}

DateTime::DateTime(int nHour, int day) : Date(day) {
	if (nHour >= 0 && nHour < 24) hour = nHour;
	else hour = 0;
	minute = 0;
	secund = 0;
}

DateTime::DateTime(int nHour, int nMinute, int nSecund, int day, int month, int year) : Date(day, month, year) {
	if (nHour >= 0 && nHour < 24) hour = nHour;
	else hour = 0;
	if (nMinute >= 0 && nMinute < 60) minute = nMinute;
	else minute = 0;
	if (nSecund >= 0 && nSecund < 60) secund = nSecund;
	else secund = 0;
}

int DateTime::getHour() {
	return hour;
}

int DateTime::getMinute() {
	return minute;
}

int DateTime::getSecund() {
	return secund;
}

int DateTime::setHour(int nHour) {
	if (nHour >= 0 && nHour < 24) {
		hour = nHour;
		return 0;
	}
	hour = 0;
	return 1;
}

int DateTime::setMinute(int nMinute) {
	if (nMinute >= 0 && nMinute < 24) {
		minute = nMinute;
		return 0;
	}
	minute = 0;
	return 1;
}

int DateTime::setSecund(int nSecund) {
	if (nSecund >= 0 && nSecund < 24) {
		secund = nSecund;
		return 0;
	}
	secund = 0;
	return 1;
}

void DateTime::set() {
	
	Date::set();
	
	string tempInput;
	int temp;

	do {
		cout << "Input hour (example: 17)\n";
		cin >> tempInput;
		cin.ignore();
		try {
			temp = stoi(tempInput);
			if (temp < 0 || temp > 23) throw - 1;
		}
		catch (invalid_argument) {
			cout << "Wrong input type. Please repeat\n";
			temp = -1;
		}
		catch (out_of_range) {
			cout << "No memory for this. Please repeat\n";
			temp = -1;
		}
		catch (...) {
			cout << "Wrong input. Please repeat\n";
			temp = -1;
		}
	} while (temp == -1);
	setHour(temp);

	do {
		cout << "Input minute (example: 30)\n";
		cin >> tempInput;
		cin.ignore();
		try {
			temp = stoi(tempInput);
			if (temp < 0 || temp > 59) throw - 1;
		}
		catch (invalid_argument) {
			cout << "Wrong input type. Please repeat\n";
			temp = -1;
		}
		catch (out_of_range) {
			cout << "No memory for this. Please repeat\n";
			temp = -1;
		}
		catch (...) {
			cout << "Wrong input. Please repeat\n";
			temp = -1;
		}
	} while (temp == -1);
	setMinute(temp);

	do {
		cout << "Input secund (example: 30)\n";
		cin >> tempInput;
		cin.ignore();
		try {
			temp = stoi(tempInput);
			if (temp < 0 || temp > 59) throw - 1;
		}
		catch (invalid_argument) {
			cout << "Wrong input type. Please repeat\n";
			temp = -1;
		}
		catch (out_of_range) {
			cout << "No memory for this. Please repeat\n";
			temp = -1;
		}
		catch (...) {
			cout << "Wrong input. Please repeat\n";
			temp = -1;
		}
	} while (temp == -1);
	setSecund(temp);
}

int DateTime::count() {
	return hour * 24 + minute * 60 + secund;
}

ostream& operator<< (ostream& out, const DateTime& datetime) {
	out << datetime.hour << ":" << datetime.minute << ":" << datetime.secund << " ";
	out << datetime.day << "." << datetime.month << "." << datetime.year << "\n";
	return out;
}

DateTime DateTime::operator=(Date date) {
	setHour(0);
	setMinute(0);
	setSecund(0);
	setDay(date.getDay());
	setMonth(date.getMonth());
	setYear(date.getYear());
	return *this;
}