#pragma once
#include <string>

class Guitar
{
	std::string type;
	std::string color;
public:
	Guitar();
	Guitar(std::string type);
	Guitar(std::string type, std::string color);
	int setType(std::string type);
	int setColor(std::string color);
	std::string getType();
	std::string getColor();
	void set();

	friend std::ostream& operator <<(std::ostream& out, const Guitar& guitar);
};

