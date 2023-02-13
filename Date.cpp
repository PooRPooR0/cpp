#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
	this->day = 1;
	this->month = 1;
	this->year = 1;
}

Date::Date(int day) {
	if (day > 0 && day <= 31) this->day = day;
	else this->day = 1;
	this->month = 1;
	this->year = 1;
}

Date::Date(int day, int month, int year) {
	if (day > 0 && day <= 31) this->day = day;
	else this->day = 1;
	if (month > 0 && month <= 12) this->month = month;
	else this->month = 1;
	if (year > 0) this->year = year;
	else this->year = 1;
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

int Date::setDay(int day) {
	if (day > 0 && day <= 31) {
		this->day = day;
		return 0;
	}

	return 1;
}

int Date::setMonth(int month) {
	if (month > 0 && month <= 12) {
		this->month = month;
		return 0;
	}

	return 1;
}

int Date::setYear(int year) {
	if (year > 0) {
		this->year = year;
		return 0;
	}

	return 1;
}

void Date::set() {
	string tempInput;
	int temp;

	do {
		cout << "Input day (example: 9)\n";
		cin >> tempInput;
		cin.ignore();
		try {
			temp = stoi(tempInput);
			if (temp < 1 || temp > 31) throw -1;
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
	setDay(temp);

	do {
		cout << "Input month (example: 4)\n";
		cin >> tempInput;
		cin.ignore();
		try {
			temp = stoi(tempInput);
			if (temp < 1 || temp > 12) throw - 1;
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
	setMonth(temp);

	do {
		cout << "Input year (example: 2021)\n";
		cin >> tempInput;
		cin.ignore();
		try {
			temp = stoi(tempInput);
			if (temp < 1) throw - 1;
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
	setYear(temp);
}

int Date::count() {
	return year * 365 + month * 31 + day;
}

Date Date::operator++ () {
	setDay(getDay()+1);
	if (getDay() > 31) {
		setDay(1);
		setMonth(getMonth() + 1);
	}
	if (getMonth() > 12) {
		setMonth(1);
		setYear(getYear() + 1);
	}
	return *this;
}

Date Date::operator++ (int) {
	Date prev = *this;
	++*this;
	return prev;
}

Date operator + (Date date1, Date date2) {
	Date date(date1.getDay() + date2.getDay(), date1.getMonth() + date2.getMonth(), date1.getYear() + date2.getYear());
	return date;
}

int Date::countDaysBetweenDates(Date date1, Date date2) {
	int sumOfDays1, sumOfDays2;

	int tempMonth = date1.getMonth();
	int tempYear = date1.getYear();
	if (tempMonth < 3) {
		tempYear--;
		tempMonth += 12;
	}
	sumOfDays1 = 365 * tempYear + tempYear / 4 - tempYear / 100 + tempYear / 400 + (153 * tempMonth - 457) / 5 + date1.getDay() - 306;

	tempMonth = date2.getMonth();
	tempYear = date2.getYear();
	if (tempMonth < 3) {
		tempYear--;
		tempMonth += 12;
	}
	sumOfDays2 = 365 * tempYear + tempYear / 4 - tempYear / 100 + tempYear / 400 + (153 * tempMonth - 457) / 5 + date2.getDay() - 306;

	return abs(sumOfDays1 - sumOfDays2);
	
	return 0;
}

ostream& operator<< (ostream& out, const Date& date) {
	out << date.day << "." << date.month << "." << date.year << "\n";
	return out;
}