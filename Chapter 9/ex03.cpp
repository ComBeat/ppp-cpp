#include "../std_lib_facilities.h"

class Name_pairs
{
	vector<string> name;
	vector<double> age;

public:
	void read_names();
	void read_ages();
	void sort();
	vector<string> get_name();
	vector<double> get_age();
};

ostream &operator<<(ostream &os, Name_pairs &np)
{
	for (int i = 0; i < np.get_name().size(); i++)
		os << '(' << np.get_name()[i] << ", " << np.get_age()[i] << ')' << endl;

	return os;
}

bool &operator==(Name_pairs &np1, Name_pairs &np2)
{
	bool value = false;
	if (np1.get_name().size() != np2.get_name().size() || np1.get_age().size() != np2.get_age().size())
		return value = false;
	for (int i = 0; i < np1.get_name().size(); i++)
		if (np1.get_name()[i] != np2.get_name()[i])
			return value = false;
	for (int i = 0; i < np1.get_age().size(); i++)
		if (np1.get_age()[i] != np2.get_age()[i])
			return value = false;

	return value = true;
}

bool &operator!=(Name_pairs &np1, Name_pairs &np2)
{
	bool value = !(np1 == np2);
	return value;
}

//Name_pairs definition
void Name_pairs::read_names()
{
	int counter = 1;

	cout << "Please enter names (\"quit\" to end the loop):" << endl;
	while (true)
	{
		string tmp_name;
		cout << counter << ": ";
		cin >> tmp_name;
		if (tmp_name == "quit")
			break;
		else
			name.push_back(tmp_name);
		counter++;
	}
	cout << endl;
}

void Name_pairs::read_ages()
{
	cout << "Please enter a corresponding age: " << endl;
	for (string s : name)
	{
		double tmp_age;
		cout << s << ": ";
		cin >> tmp_age;
		age.push_back(tmp_age);
	}
	cout << endl;
}

void Name_pairs::sort()
{
	vector<string> name_presort = name;
	vector<double> age_copy = age;

	std::sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); i++)
		for (int j = 0; j < name_presort.size(); j++)
			if (name[i] == name_presort[j])
				age[i] = age_copy[j];
}

vector<string> Name_pairs::get_name()
{
	return name;
}

vector<double> Name_pairs::get_age()
{
	return age;
}

int main()
{
	Name_pairs np;
	np.read_names();
	np.read_ages();
	cout << "Before sort" << endl;
	cout << np;
	np.sort();
	cout << "\nAfter sort" << endl;
	cout << np;
}
