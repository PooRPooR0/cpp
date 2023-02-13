#pragma once
#include <string>

class Position
{
	std::string posName;
	int minSalary;
public:
	Position();
	Position(std::string posName);
	Position(std::string posName, int minSalary);
	int setPosName(std::string posName);
	int setMinSalary(int minSalary);
	std::string getPosName();
	int getMinSalary();
	void set();
	float convertSalaryDollar();

	friend std::ostream& operator <<(std::ostream& out, const Position& position);
};