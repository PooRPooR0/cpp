#include "Position.h"
#include <iostream>
#include <string>

using namespace std;

Position::Position() {
	this->posName = "Empty";
	this->minSalary = 0;
}

Position::Position(string posName) {
	if (posName != "" || posName != "\n") this->posName = posName;
	else this->posName = "Empty";
	this->minSalary = 0;
}

Position::Position(string posName, int minSalary) {
	if (posName != "" || posName != "\n") this->posName = posName;
	else this->posName = "Empty";
	if (minSalary >= 0) this->minSalary = minSalary;
	else this->minSalary = 0;
}

int Position::setPosName(string posName) {
	if (posName != "" || posName != "\n") {
		this->posName = posName;
		return 0;
	}
	return 1;
}

int Position::setMinSalary(int minSalary) {
	if (minSalary >= 0) {
		this->minSalary = minSalary;
		return 0;
	}
	return 1;
}

string Position::getPosName() {
	return posName;
}

int Position::getMinSalary() {
	return minSalary;
}

void Position::set() {
	string temp = "";
	while (temp == "" || temp == "\n") {
		cout << "Input position name (example: Manager)\n";
		getline(cin, temp);
		if (temp == "" || temp == "\n") cout << "Error. Please repeat\n";
	}
	setPosName(temp);

	int tempNum;
	do {
		cout << "Input minimal salary (example: 10000)\n";
		cin >> temp;
		cin.ignore();
		try {
			tempNum = stoi(temp);
			if (tempNum < 0) throw - 1;
		}
		catch (invalid_argument) {
			cout << "Wrong input type. Please repeat\n";
			tempNum = -1;
		}
		catch (out_of_range) {
			cout << "No memory for this. Please repeat\n";
			tempNum = -1;
		}
		catch (...) {
			cout << "Wrong input. Please repeat\n";
			tempNum = -1;
		}
	} while (tempNum == -1);
	setMinSalary(tempNum);
}

float Position::convertSalaryDollar() {
	return getMinSalary() / 69.8;
}

ostream& operator<< (ostream& out, const Position& position) {
	out << position.posName << " " << position.minSalary << " Rub";
	return out;
}