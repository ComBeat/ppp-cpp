// Sentence:
// 		Subject Verb
// 		Sentence Conjunction Sentence
// Subject:
// 		Noun
// 		"the"
// Conjunction:
// 		"and"
// 		"or"
// 		"but"
// Noun:
// 		"birds"
// 		"fish"
// 		"C++"
// Verb:
// 		"rules"
// 		"fly"
// 		"swim"

#include <std_lib_facilities.h>

class String_stream
{
  public:
	String_stream();
	string get();
	void put_back(string str);

  private:
	bool full;
	string buffer;
};

String_stream::String_stream()
	: full(false), buffer("") {}

string String_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	string str = "";
	cin >> str;
	return str;
}

void String_stream::put_back(string str)
{
	if (full)
		error("put_back() into a full buffer");
	buffer = str;
	full = true;
}

String_stream sstr;

bool verb()
{
	string s = sstr.get();

	if (s == "rules" || s == "fly" || s == "swim")
		return true;
	else
		return false;
}

bool noun()
{
	string s = sstr.get();

	if (s == "birds" || s == "fish" || s == "C++")
		return true;
	else
		return false;
}

bool conjunction()
{
	string s = sstr.get();

	if (s == "and" || s == "or" || s == "but")
		return true;
	else
		return false;
}

bool subject()
{
	string s = "";
	s == sstr.get();

	if (s == "the")
		return noun();
	else
	{
		sstr.put_back(s);
		return noun();
	}
}

bool sentence()
{
	// return ((subject() && verb()) || (sentence() && conjunction() && sentence()));
	bool b1 = (subject() && verb());
	// bool b2 = (sentence() && conjunction() && sentence());
	// return (b1 || b2);
	return b1;
}

int main()
{
	bool ok = false;

	try
	{
		do
		{
			string str;
			cout << "Input: ";
			cin >> str;

			ok = sentence();
			if (!ok)
			{
				cout << "Not ok!\n";
				return 0;
			}

			string s = sstr.get();
			if (s == ".")
			{
				cout << "OK!\n";
				return 0;
			}
			else
			{
				sstr.put_back(s);
				ok = conjunction();
				if (!ok)
				{
					cout << "Not OK!\n";
					return 0;
				}
			}
		} while (ok);
	}
	catch (exception &e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown error!\n";
		return 2;
	}
}
