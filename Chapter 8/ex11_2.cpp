/**
 * Alternative with struct
 */

#include "../std_lib_facilities.h"

struct VectorProperties
{
	int max;
	int min;
	double mean;
	int median;

	VectorProperties();
} myVector; //Variablename for this struct

VectorProperties::VectorProperties()
	: max(0), min(0), mean(0.0), median(0) {}

int maxValue(const vector<int> &v)
{
	int max = v[0];

	for (int i : v)
		if (i > max)
			max = i;

	return max;
}

int minValue(const vector<int> &v)
{
	int min = v[0];

	for (int i : v)
		if (i < min)
			min = i;

	return min;
}

double meanValue(const vector<int> &v)
{
	double sum = 0.0;

	for (int i : v)
		sum += i;

	return (double)(sum / v.size());
}

int medianValue(vector<int> &v)
{
	sort(v.begin(), v.end());

	return v[v.size() / 2];
}

int main()
{
	vector<int> values = {4325, 1342, 3562334, 625, 832375};
	VectorProperties vectorProperties;

	myVector.max = maxValue(values);
	myVector.min = minValue(values);
	myVector.mean = meanValue(values);
	myVector.median = medianValue(values);

	cout << "Maximum:\t" << myVector.max << endl;
	cout << "Minimum:\t" << myVector.min << endl;
	cout << "Mean:\t\t" << myVector.mean << endl;
	cout << "Median:\t\t" << myVector.median << endl;
}
