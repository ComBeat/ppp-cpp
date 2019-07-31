/**
 * Compare the two name vectors, then order age
 */

#include "../std_lib_facilities.h"

vector<string> name;
vector<double> age;

void print(const vector<double> &age_sorted)
{
	for (int i = 0; i < name.size(); i++)
		cout << "Name: " << name[i] << "\tAge: " << age_sorted[i] << endl;
}

void write_pairs()
{
	string str = "";
	double n = 0;
	int i = 0;

	cout << "Please enter names and the corresponding ages" << endl;
	while (cin >> str >> n && str != "NoName")
	{
		name.push_back(str);
		age.push_back(n);
	}
}

//Alternative for a specific amount (5) of name-age-pairs
void write_pairs_alternative()
{
	string str = "";
	double n = 0;
	int i = 0;

	cout << "Please enter 5 names and the corresponding ages" << endl;
	do
	{
		cin >> str >> n;
		cout << str << n << endl;
		name.push_back(str);
		age.push_back(n);
		cout << i << endl;
		i++;
	} while (i < 5);
}

vector<double> sort_age(const vector<string> &name_copy)
{
	vector<double> age_new;

	for (string str : name)
		for (int i = 0; i < name_copy.size(); i++)
			if (str == name_copy[i])
				age_new.push_back(age[i]);

	return age_new;
}

int main()
{
	vector<string> name_copy;
	vector<double> age_sorted;

	write_pairs();

	name_copy = name;

	cout << "\nBefore sort" << endl;
	print(age);
	sort(name.begin(), name.end());
	age_sorted = sort_age(name_copy);
	cout << "\nAfter sort" << endl;
	print(age_sorted);
}
