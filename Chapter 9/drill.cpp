// Chapter 09, drill

#include "../std_lib_facilities.h"
#include "Chrono.h"

void chrono941()
{
	using namespace Chrono941;

	Date today;
	Date tomorrow;
	Date invalid_date;

	init_day(today, 1978, 6, 25);
	tomorrow = today;
	add_day(tomorrow, 1);
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	init_day(invalid_date, 2004, 13, -5);
	cout << "Invalid date: " << invalid_date << endl;
}

int main()
{
	chrono941();
}
