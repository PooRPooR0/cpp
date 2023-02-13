#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer() {
	fio = "Empthy";
}

Customer::Customer(std::string nFio) {
	if (nFio != "" || nFio != "\n") fio = nFio;
	else fio = "Empty";
}

int Customer::setFio(string nFio) {
	if (nFio != "" || nFio != "\n") {
		fio = nFio;
		return 1;
	}
	else fio = "Empty";
	return 0;
}

string Customer::getFio() {
	return fio;
}

void Customer::set() {
	string temp = "";
	while (temp == "" || temp == "\n") {
		cout << "Input worker`s FIO (example: Ivanov Ivan Ivanovich)\n";
		getline(cin, temp);
		if (temp == "" || temp == "\n") cout << "Error. Please repeat\n";
	}
	setFio(temp);
}

std::ostream& operator <<(std::ostream& out, const Customer& cust) {
	out << cust.fio;
	
	return out;
}