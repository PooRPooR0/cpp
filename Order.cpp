#include "Order.h"
#include <iostream>
#include <string>

using namespace std;

int Order::count = 0;

Order::Order() {
	count++;
	this->date = Date();
	customer = Customer();
	this->guitar = Guitar();
	this->worker = Worker();
	this->cost = 0;
}

Order::Order(Date date) {
	count++;
	this->date = date;
	customer = Customer();
	this->guitar = Guitar();
	this->worker = Worker();
	this->cost = 0;
}

Order::Order(Date date, Customer nCust, Guitar guitar, Worker worker, int cost) {
	count++;
	this->date = date;
	customer = nCust;
	this->guitar = guitar;
	this->worker = worker;
	if (cost >= 0) this->cost = cost;
	else this->cost = 0;
}

int Order::setDate(Date date) {
	this->date = date;
	return 0;
}

int Order::setCustomer(Customer nCust) {
	customer = nCust;
	return 0;
}

int Order::setGuitar(Guitar guitar) {
	this->guitar = guitar;
	return 0;
}

int Order::setWorker(Worker worker) {
	this->worker = worker;
	return 0;
}

int Order::setCost(int cost) {
	if (cost >= 0) {
		this->cost = cost;
		return 0;
	}
	return 1;
}

Date Order::getDate() {
	return date;
}

Customer Order::getCustomer() {
	return customer;
}

Guitar Order::getGuitar() {
	return guitar;
}

Worker Order::getWorker() {
	return worker;
}

int Order::getCost() {
	return cost;
}

void Order::set() {
	Date tempDate;
	tempDate.set();
	setDate(tempDate);

	Customer cust;
	cust.set();
	setCustomer(cust);

	Guitar tempGuitar;
	tempGuitar.set();
	setGuitar(tempGuitar);

	Worker tempWorker;
	tempWorker.set();
	setWorker(tempWorker);

	string temp;
	int tempNum;
	do {
		cout << "Input cost (example: 2000)\n";
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
	setCost(tempNum);
}

int Order::getCount() {
	return count;
}

int Order::setCount(int nCount) {
	if (nCount >= 0) {
		count = nCount;
		return 0;
	}
	return 1;
}

ostream& operator<< (ostream& out, const Order& order) {
	out << order.date << "\n" << order.customer << "\n";
	out << order.guitar << "\n" << order.worker << order.cost << " Rub\n";
	return out;
}