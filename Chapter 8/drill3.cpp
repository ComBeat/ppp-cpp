#include "../std_lib_facilities.h"

namespace X
{
int var;
void print() { cout << "var from X: " << var << endl; };
} // namespace X

namespace Y
{
int var;
void print() { cout << "var from Y: " << var << endl; };
} // namespace Y

namespace Z
{
int var;
void print() { cout << "var from Z: " << var << endl; };
} // namespace Z

int main()
{
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::print;
		using Z::var;
		var = 11;
		print();
	}
	print();
	X::print();
}
