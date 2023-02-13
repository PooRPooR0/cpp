#pragma once
#include <string>
#include "Date.h"
#include "Worker.h"
#include "Guitar.h"
#include "Customer.h"

class Order
{
	Date date;
	Customer customer;
	Guitar guitar;
	Worker worker;
	int cost;
	static int count;
public:
	Order();
	Order(Date date);
	Order(Date date, Customer nCust, Guitar guitar, Worker worker, int cost);
	int setDate(Date date);
	int setCustomer(Customer nCust);
	int setGuitar(Guitar guitar);
	int setWorker(Worker worker);
	int setCost(int cost);
	Date getDate();
	Customer getCustomer();
	Guitar getGuitar();
	Worker getWorker();
	int getCost();
	void set();
	static int getCount();
	static int setCount(int nCount);

	friend std::ostream& operator <<(std::ostream& out, const Order& order);
};

