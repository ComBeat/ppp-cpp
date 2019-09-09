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
			  << ", " << d.month
			  << ", " << d.day
			  << ')';
}
} // namespace Chrono941

namespace Chrono942
{
Date::Date(int y, int m, int d) : year{y}, month{m}, day{d}
{
	if (m < 1 || m > 12 || d < 1 || d > 31)
		error("Invalid date!");
}

void Date::add_day(int n)
{
	if (day + n > 31)
		cout << "Day becomes invalid!" << endl;
	else
		day += n;
}

ostream &operator<<(ostream &os, const Date &d)
{
	return os << '(' << d.year
			  << ", " << d.month
			  << ", " << d.day
			  << ')';
}
} // namespace Chrono942

namespace Chrono943
{
Date::Date(int y, int m, int d) : year(y), month(m), day(d)
{
	if (m < 1 || m > 12 || d < 1 || d > 31)
		error("Invalid date!");
}

void Date::add_day(int n)
{
	if (day + n > 31)
		cout << "Day becomes invalid!" << endl;
	else
		day += n;
}

ostream &operator<<(ostream &os, Date &d)
{
	return os << '(' << d.get_year()
			  << ", " << d.get_month()
			  << ", " << d.get_day()
			  << ')';
}
} // namespace Chrono943

namespace Chrono971
{
Date::Date(int y, Month m, int d) : year(y), month(m), day(d)
{
	if (m < Month::jan || m > Month::dec || d < 1 || d > 31)
		error("Date is invalid!");
}

void Date::add_day(int n)
{
	if (day + n > 31)
		cout << "Day becomes invalid!" << endl;
	else
		day += n;
}

ostream &operator<<(ostream &os, Date &d)
{
	return os << '(' << d.get_year()
			  << ", " << d.get_month()
			  << ", " << d.get_day()
			  << ')';
}
} // namespace Chrono971

namespace Chrono974
{
}
