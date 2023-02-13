#include "Guitar.h"
#include <iostream>
#include <string>

using namespace std;

Guitar::Guitar() {
	this->type = "Empty";
	this->color = "Empty";
}

Guitar::Guitar(string type) {
	if (type != "" || type != "\n") this->type = type;
	else this->type = "Empty";
	this->color = "Empty";
}

Guitar::Guitar(string type, string color) {
	if (type != "" || type != "\n") this->type = type;
	else this->type = "Empty";
	if (color != "" || color != "\n") this->color = color;
	else this->color = "Empty";
}

int Guitar::setType(string type) {
	if (type != "" || type != "\n") {
		this->type = type;
		return 0;
	}
	return 1;
}

int Guitar::setColor(string color) {
	if (color != "" || color != "\n") {
		this->color = color;
		return 0;
	}
	return 1;
}

std::string Guitar::getType() {
	return type;
}

std::string Guitar::getColor() {
	return color;
}

void Guitar::set() {
	string temp = "";
	while (temp == "" || temp == "\n") {
		cout << "Input guitar type (example: Acoustic)\n";
		getline(cin, temp);
		if (temp == "" || temp == "\n") cout << "Error. Please repeat\n";
	}
	setType(temp);

	temp = "";
	while (temp == "" || temp == "\n") {
		cout << "Input guitar color (example: Yellow)\n";
		getline(cin, temp);
		if (temp == "" || temp == "\n") cout << "Error. Please repeat\n";
	}
	setColor(temp);
}

ostream& operator<< (ostream& out, const Guitar& guitar) {
	out << guitar.type << " " << guitar.color;
	return out;
}