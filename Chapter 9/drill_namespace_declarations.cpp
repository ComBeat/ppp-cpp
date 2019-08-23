#include "../std_lib_facilities.h"
#include "Chrono.h"

namespace Chrono941
{
void init_day(Date &date, int year, int month, int day)
{
	date.year = year, date.month = month, date.day = day;

	if (valid_date(date))
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

ostream &operator<<(ostream &os, const Date &d)
{
	return os << '(' << d.year
			  << ',' << d.month
			  << ',' << d.day
			  << ')';
}

bool valid_date(Date &date)
{
}
} // namespace Chrono941
