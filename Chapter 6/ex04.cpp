#include "../std_lib_facilities.h"

class Name_value
{
public:
	string name;
	int score;
	Name_value(string name, int score)
		: name(name), score(score) {}
};

int main()
{
	try
	{
		string name = "";
		int score = -1;
		vector<Name_value> nv;

		do
		{
			cout << "Enter name and score: ";
			cin >> name >> score;

			nv.push_back(Name_value(name, score));
		} while (!(name == "NoName" && score == 0));

		for (int i = 0; i < nv.size(); ++i)
		{
			cout << "Name: " << nv[i].name << "\nScore: " << nv[i].score << '\n';
		}
	}

	catch (exception &e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown exception\n";
		return 2;
	}
}
