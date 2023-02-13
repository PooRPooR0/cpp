#pragma once
#include "Human.h"

class Customer : public Human
{
private:
	std::string fio;
public:
	Customer();
	Customer(std::string fio);
	int setFio(std::string fio) override;
	std::string getFio() override;
	void set();

	friend std::ostream& operator <<(std::ostream& out, const Customer& cust);
};
