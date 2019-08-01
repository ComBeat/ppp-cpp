#include "../std_lib_facilities.h"

int maxv(const vector<int> &v)
{
	int h = numeric_limits<int>::min();

	for (int i : v)
		if (i > h)
			h = i;

	return h;
}

int minv(const vector<int> &v)
{
	int m = numeric_limits<int>::max();

	for (int i : v)
		if (i < m)
			m = i;

	return m;
}

double meanv(const vector<int> &v)
{
	double sum = 0.0;

	for (int i : v)
		sum += i;

	return sum / v.size();
}

int medv(vector<int> &v)
{
	sort(v.begin(), v.end());

	return v[v.size() / 2];
}

int main()
{
	vector<int> values = {4325, 1342, 3562334, 625, 832375};

	cout << "Maximum:\t" << maxv(values) << endl;
	cout << "Minimum:\t" << minv(values) << endl;
	cout << "Mean:\t\t" << meanv(values) << endl;
	cout << "Median:\t\t" << medv(values) << endl;
}
