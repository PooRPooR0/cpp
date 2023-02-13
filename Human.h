#pragma once
#include <string>

class Human
{
public:
	virtual int setFio(std::string fio) = 0;
	virtual std::string getFio() = 0;
};

