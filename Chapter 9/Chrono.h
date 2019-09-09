
//
// This is example code from Chapter 9.8 "The Date class" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

namespace Chrono
{

//------------------------------------------------------------------------------

class Date
{
public:
	enum Month
	{
		jan = 1,
		feb,
		mar,
		apr,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		dec
	};

	class Invalid
	{
	}; // to throw as exception

	Date(int y, Month m, int d); // check for valid date and initialize
	Date();						 // default constructor
	// the default copy operations are fine

	// non-modifying operations:
	int day() const { return d; }
	Month month() const { return m; }
	int year() const { return y; }

	// modifying operations:
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

private:
	int y;
	Month m;
	int d;
};

//------------------------------------------------------------------------------

bool is_date(int y, Date::Month m, int d); // true for valid date

//------------------------------------------------------------------------------

bool leapyear(int y); // true if y is a leap year

//------------------------------------------------------------------------------

bool operator==(const Date &a, const Date &b);
bool operator!=(const Date &a, const Date &b);

//------------------------------------------------------------------------------

ostream &operator<<(ostream &os, const Date &d);
istream &operator>>(istream &is, Date &dd);

//------------------------------------------------------------------------------

} // namespace Chrono

namespace Chrono941
{
struct Date
{
	int year;
	int month;
	int day;
};

//Helper functions
void init_day(Date &date, int year, int month, int day);

void add_day(Date &date, int n);

ostream &operator<<(ostream &os, const Date &d);
} // namespace Chrono941

namespace Chrono942
{
struct Date
{
	int year, month, day;
	Date(int year, int month, int day);
	void add_day(int n);
};

ostream &operator<<(ostream &os, const Date &d);
} // namespace Chrono942

namespace Chrono943
{
class Date
{
	int year, month, day;

public:
	Date(int y, int m, int d);
	void add_day(int n);
	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
};

ostream &operator<<(ostream &os, Date &d);
} // namespace Chrono943

namespace Chrono971
{
class Date
{
public:
	enum Month
	{
		jan = 1,
		feb,
		mar,
		apr,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		dec
	};

	Date(int y, Month m, int d);
	void add_day(int n);
	int get_year() { return year; }
	Month get_month() { return month; }
	int get_day() { return day; }

private:
	int year;
	Month month;
	int day;
};

ostream &operator<<(ostream &os, Date &d); // Date& d not const on purpose
} // namespace Chrono971

namespace Chrono974
{
class Date
{
public:
	enum Month
	{
		jan = 1,
		feb,
		mar,
		apr,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		dec
	};

	Date(int y, Month m, int d);
	int get_year() const;
	Month get_month() const;
	int get_day() const;

	void add_year(int n);
	void add_month(int n);
	void add_day(int n);

private:
	int year;
	Month month;
	int day;
};

ostream &operator<<(ostream &os, Date &d); // Date& d not const on purpose
} // namespace Chrono974
