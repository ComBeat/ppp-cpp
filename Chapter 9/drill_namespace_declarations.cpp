#include "../std_lib_facilities.h"
#include "Chrono.h"

namespace Chrono941
{
void init_day(Date &date, int year, int month, int day)
{
	if (day < 1 || day > 31 || month < 1 || month > 12)
		error("Invalid date!");

	date.year = year;
	date.month = month;
	date.day = day;
}

void add_day(Date &date, int n)
{
	if (date.day + n > 31)
		cout << "Day becomes invalid!" << endl;
	else
		date.day += n;
}

ostream &operator<<(ostream &os, const Date &d)
{
	return os << '(' << d.year
			  << ',' << d.month
			  << ',' << d.day
			  << ')';
}
} // namespace Chrono941
