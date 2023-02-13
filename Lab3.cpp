#include <iostream>
#include "Date.h"
#include "DateTime.h"
#include "Position.h"
#include "Worker.h"
#include "Guitar.h"
#include "Order.h"

using namespace std;

int main()
{
	Date d = Date(5,10,20);
	DateTime dt = DateTime();
	cout << dt.count() << "\n";
	cout << d.count() << "\n";
	dt = d;
	cout << dt;

	return 0;
}