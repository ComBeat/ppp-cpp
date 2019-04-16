#include <std_lib_facilities.h>

vector<string> names;
vector<int> scores;

bool vector_input(string name)
{
	int elem = 0;

	for (int i = 0; i < names.size(); i++, elem++)
	{
		if (names[i] == name)
		{
			cout << "Error!!1!" << endl;
			return false;
		}
		if (elem == names.size() - 1)
			return true;
	}
}

void print()
{
	for (int i = 0; i < names.size(); i++)
	{
		cout << "Name: " << names[i] << "\t\tScore: " << scores[i] << endl;
	}
}

int main()
{
	string name;
	int score;
	bool fentr = true;

	do
	{
		cout << "Enter name and score: ";
		cin >> name >> score;

		if (fentr)
		{
			names.push_back(name);
			scores.push_back(score);
			fentr = false;
		}
		else
		{
			if (vector_input(name))
			{
				names.push_back(name);
				scores.push_back(score);
			}
		}
	} while (!(name == "NoName" && score == 0));

	print();
}
