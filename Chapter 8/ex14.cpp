#include "../std_lib_facilities.h"

void f(const int n)
{
	// n++; const cannot be altered
	cout << n << endl;
}

int main()
{
	f(10);
}
