#include "../std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//doesn't compile, because assignment of read-only reference ‘a/b’
void swap_cr(const int &a, const int &b)
{
	// int temp;
	// temp = a;
	// a = b;
	// b = temp;
}

int main()
{
	//doesn't compile with swap_r, because is non const
	//swap_cr: assignment of read-only reference ‘a’
	int x = 7;
	int y = 9;

	/* cout << x << '\n'
		 << y << '\n'
		 << endl;
	swap_v(x, y);

	cout << x << '\n'
		 << y << '\n'
		 << endl;
	swap_v(7, 9);

	cout << x << '\n'
		 << y << '\n'
		 << endl; */

	//doesn't compile with swap_(c)r, because reference if type int& to const int discards qualifiers
	const int cx = 7;
	const int cy = 9;

	/* cout << cx << '\n'
		 << cy << '\n'
		 << endl;
	swap_v(cx, cy);

	cout << cx << '\n'
		 << cy << '\n'
		 << endl;
	swap_v(7, 9);

	cout << cx << '\n'
		 << cy << '\n'
		 << endl; */

	//implicit conversion fom double to int
	//doesn't compile with swap_(c)r, because cannot bind non-const int& to int
	double dx = 7.7;
	double dy = 9.9;

	/* cout << dx << '\n'
		 << dy << '\n'
		 << endl;
	swap_v(dx, dy);

	cout << dx << '\n'
		 << dy << '\n'
		 << endl;
	swap_v(7.7, 9.9);

	cout << dx << '\n'
		 << dy << '\n'
		 << endl; */
}
