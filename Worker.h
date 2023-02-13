#pragma once
#include <string>
#include "Position.h"
#include "Human.h"

class Worker : public Human
{
	std::string fio;
	Position position;
	int salary;
	static int workersCount;
public:
	Worker();
	Worker(std::string fio);
	Worker(std::string fio, Position position, int salary);
	int setFio(std::string fio) override;
	int setPosition(Position position);
	int setSalary(int salary);
	std::string getFio() override;
	Position getPosition();
	int getSalary();
	void set();
	int countSalaryDifference();

	friend std::ostream& operator <<(std::ostream& out, const Worker& worker);
};