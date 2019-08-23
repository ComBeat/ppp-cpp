// Chapter 09, drill

#include "../std_lib_facilities.h"
#include "Chrono.h"

void init_day(Date &date, int year, int month, int day)
{
	date.year = year, date.month = month, date.day = day;
}

void add_day(Date &date, int n)
{
	if (date.day + n > 31)
	{
		cout << date.day + n << endl;
		cout << "Day becomes invalid!" << endl;
	}
	else
		date.day += n;
}

void chrono941()
{
	using namespace Chrono941;

	Date today;
	Date tomorrow;

	init_day(today, 1978, 6, 25);
	tomorrow = today;
	add_day(tomorrow, 1);
}

int main()
{
	chrono941();
}
