/**
 * ex04: approx. 1836311903
 */

#include "../std_lib_facilities.h"

void print(string label, vector<int> v)
{
	int x = 1;
	for (int i : v)
	{
		cout << x << ": " << i << endl;
		x++;
	}
}

void fibonacci(int x, int y, vector<int> &v, int n)
{
	v.push_back(x);
	v.push_back(y);

	for (int i = 2; i < n; i++)
	{
		v.push_back(x + y);
		// y += x;
		y = v[i];
		// x = y - x;
		x = v[i - 1];
	}
}

int main()
{
	vector<int> v;

	fibonacci(1, 1, v, 48);
	print("String", v);
}
