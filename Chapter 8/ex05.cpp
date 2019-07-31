#include "../std_lib_facilities.h"

void print(const vector<int> v)
{
	// int x = 1;
	for (int i : v)
	{
		// cout << x << ": " << i << endl;
		cout << i << endl;
		// x++;
	}
}

//Reverse the vector and operate on a copy (pass-by-value)
vector<int> swap1(vector<int> v)
{
	vector<int> v_new;

	for (int i = v.size() - 1; i >= 0; i--)
	{
		v_new.push_back(v[i]);
	}

	return v_new;
}

//Reverse the vector and operate on the given vector (pass-by-reference)
void swap2(vector<int> &v)
{
	for (int i = 0; i <= v.size() / 2; i++)
	{
		swap(v[i], v[v.size() - 1 - i]);
	}
}

int main()
{
	vector<int> v_orig = {3, 5, 7, 42, 666};
	vector<int> v_swap1 = swap1(v_orig);

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
