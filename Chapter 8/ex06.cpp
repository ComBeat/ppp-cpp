#include "../std_lib_facilities.h"

void print(const vector<string> v)
{
	// int x = 1;
	for (string str : v)
	{
		// cout << x << ": " << i << endl;
		cout << str << endl;
		// x++;
	}
}

//Reverse the vector and operate on a copy (pass-by-value)
vector<string> swap1(const vector<string> &v)
{
	vector<string> v_new;

	for (int i = v.size() - 1; i >= 0; i--)
	{
		v_new.push_back(v[i]);
	}

	return v_new;
}

//Reverse the vector and operate on the given vector (pass-by-reference)
void swap2(vector<string> &v)
{
	for (int i = 0; i <= v.size() / 2; i++)
	{
		swap(v[i], v[v.size() - 1 - i]);
	}
}

int main()
{
	vector<string> v_orig = {"hello", "world", "!"};
	vector<string> v_swap1 = swap1(v_orig);

	cout << "Orig" << endl;
	print(v_orig);
	cout << "\nSwap1" << endl;
	print(v_swap1);
	cout << "\nOrig" << endl;
	print(v_orig);
	swap2(v_orig);
	cout << "\nSwap2" << endl;
	print(v_orig);
}
