#include "Worker.h"
#include "Position.h"
#include <iostream>
#include <string>

using namespace std;

Worker::Worker() {
	this->fio = "Empty";
	this->position = Position();
	this->salary = 0;
}

Worker::Worker(string fio) {
	if (fio != "" || fio != "\n") this->fio = fio;
	else this->fio = "Empty";
	this->position = Position();
	this->salary = 0;
}

Worker::Worker(string fio, Position position, int salary) {
	if (fio != "" || fio != "\n") this->fio = fio;
	else this->fio = "Empty";
	this->position = position;
	if (salary >= 0) this->salary = salary;
	else this->salary = 0;
}

int Worker::setFio(string fio) {
	if (fio != "" || fio != "\n") {
		this->fio = fio;
		return 0;
	}
	return 1;
}

int Worker::setPosition(Position position) {
	this->position = position;
	return 0;
}

int Worker::setSalary(int salary) {
	if (salary >= 0) {
		this->salary = salary;
		return 0;
	}
	return 1;
}

string Worker::getFio() {
	return fio;
}

Position Worker::getPosition() {
	return position;
}

int Worker::getSalary() {
	return salary;
}

void Worker::set() {
	string temp = "";
	while (temp == "" || temp == "\n") {
		cout << "Input worker`s FIO (example: Ivanov Ivan Ivanovich)\n";
		getline(cin, temp);
		if (temp == "" || temp == "\n") cout << "Error. Please repeat\n";
	}
	setFio(temp);

	Position tempPos;
	tempPos.set();
	setPosition(tempPos);

	int tempNum;
	do {
		cout << "Input worker`s salary (example: 30000)\n";
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
	setSalary(tempNum);
}

int Worker::countSalaryDifference() {
	return getSalary() - getPosition().getMinSalary();
}

ostream& operator<< (ostream& out, const Worker& worker) {
	out << worker.fio << "\n" << worker.position << "\n" << worker.salary << " Rub\n";
	return out;
}