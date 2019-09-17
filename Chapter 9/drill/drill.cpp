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
	cout << "Invalid date: " << invalid_date << endl; //isn't called
}

void chrono942()
{
	using namespace Chrono942;

	Date today{2005, 06, 25};
	Date tomorrow{today};
	Date invalid_date{1970, 01, 01};

	tomorrow.add_day(1);
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	invalid_date = {2004, 13, -5};
	cout << "Invalid date: " << invalid_date << endl; //isn't called
}

void chrono943()
{
	using namespace Chrono943;

	Date today{2005, 06, 25};
	Date tomorrow{today};
	Date invalid_date{1970, 01, 01};

	tomorrow.add_day(1);
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	invalid_date = {2004, 13, -5};
	cout << "Invalid date: " << invalid_date << endl; //isn't called
}

void chrono971()
{
	using namespace Chrono971;

	Date today{2005, Date::jun, 25};
	Date tomorrow{today};
	Date invalid_date{1970, Date::jan, 01};

	tomorrow.add_day(1);
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	invalid_date = {2004, Date::oct, -5};
	cout << "Invalid date: " << invalid_date << endl; //isn't called
}

void chrono974()
{
	using namespace Chrono974;

	Date today{2005, Date::jun, 25};
	Date tomorrow{today};
	Date invalid_date{1970, Date::jan, 01};

	tomorrow.add_day(1);
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	invalid_date = {2004, Date::oct, -5};
	cout << "Invalid date: " << invalid_date << endl; //isn't called
}

int main()
{
	chrono974();
}
