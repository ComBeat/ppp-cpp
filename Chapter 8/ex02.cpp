#include "../std_lib_facilities.h"

void print(string label, vector<int> v)
{
	for (int i : v)
		cout << i << '\n';
}

int main()
{
	vector<int> v = {3, 42, 5, 666};
	print("String", v);
}
