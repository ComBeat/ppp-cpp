/**
 * 1: Done
 * 2: Done
 * 3: Done
 * 4: Done
 * 5: Done
 * 6: Done
 * 7: Done
 * 8: Done
 * 9: Faculty-function: Done with basic functionality
 *    Other ideas:      history of calculations to scroll through with arrow keys
 *                      show binary value if possible
 * 10: Not finished
 * 11: Done (kind of *cough* Chapter 4 - ex14.cpp *cough*) and Chapter 5 - ex07.cpp
 */

/*
	A simple calculator

    Grammar:
    Expression
	Term
    Primary
    Declaration
    Statement

    Print:
        ";"
    Quit:
        "quit"

    Expression:
        Term
        Expression "+" Term
        Expression "-" Term
    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
        Term "%" Primary
    Primary:
        Number
        "(" Expression ")"
        "-" Primary
        "+" Primary
        "sqrt(" Expression ")"
        "pow(" Expression "," Integer ")"
        Name
        Name "=" Expression
	Declaration:
		"let" Name "=" Expression
		"const" Name "=" Expression
	Sequence:
		letter
		digit
		"_"
		letter Sequence
		digit Sequence
		"_" Sequence
    Number:
        floating-point-literal

    bugs
    -1e; e.g. puts the program into a "Bad token" loop
*/

#include "std_lib_facilities.h"

//Simple Token
struct Token
{
	char kind;
	double value;
	string name;

	Token(char ch) : kind(ch), value(0) {}

	Token(char ch, double val) : kind(ch), value(val) {}

	Token(char ch, string str) : kind(ch), name(str) {}
};

//stream of tokens
class Token_stream
{
	bool full;
	Token buffer;

  public:
	Token_stream() : full(0), buffer(0) {} //empty Token_stream

	Token get();

	void unget(Token t)
	{
		buffer = t;
		full = true;
	}

	void ignore(char);
};

//global const variables
//Tokens
const char assignmentchar = '=';
const char constchar = 'c';
const char facultychar = '!';
const char helpchar = 'h';
const char letchar = 'l';
const char namechar = 'a';
const char numberchar = '8';
const char powchar = 'p';
const char printchar = ';';
const char quitchar = 'q';
const char sqrtchar = 's';
const int kvalue = 1000;
//Keywords
const string constkey = "const";
const string helpkey = "help";
const string letkey = "let";
const string powkey = "pow";
const string quitkey = "quit";
const string sqrtkey = "sqrt";

Token Token_stream::get()
{
	//is buffer full
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin.get(ch);
	while (isspace(ch))
	{
		if (ch == '\n')
			return Token(printchar);
		cin.get(ch);
	}
	switch (ch)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case printchar:
	case 'k':
	case facultychar:
	case '=':
	case ',':
		return Token(ch);
	case '.':
		// error("No decimal numbers allowed");
		// break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget();
		double val;
		cin >> val;
		return Token(numberchar, val);
	}
	default:
		if (isalpha(ch) || ch == '_')
		{
			string s;
			s += ch;
			while ((cin.get(ch) && (isalpha(ch) || isdigit(ch))) || ch == '_')
				s += ch;
			cin.unget();
			if (s == helpkey)
				return Token(helpchar);
			if (s == constkey)
				return Token(constchar);
			if (s == letkey)
				return Token(letchar);
			if (s == quitkey)
				return Token(quitchar);
			if (s == sqrtkey)
				return Token(sqrtchar);
			if (s == powkey)
				return Token(powchar);
			return Token(namechar, s);
		}
		error("Bad token");
	}

	return 0;
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c)
			return;
}

struct Variable
{
	string name;
	double value;
	bool is_constant;

	Variable(string n, double v, bool b) : name(n), value(v), is_constant(b) {}
};

struct Symbol_Table
{
	double get(string name);

	void set(string name, double value);

	bool is_declared(string name);

	double declare(string name, double value, bool b);

  private:
	vector<Variable> var_table;
};

//Search for a variable and return the value
double Symbol_Table::get(string name)
{
	for (int i = 0; i < var_table.size(); i++)
		if (var_table[i].name == name)
			return var_table[i].value;
	error("Get: Undefined name ", name);

	return 0;
}

//Search for variable and set a new value
void Symbol_Table::set(string name, double value)
{
	for (int i = 0; i < var_table.size(); i++)
		if (var_table[i].name == name)
		{
			if (var_table[i].is_constant)
				error("Variable is a constant!");
			var_table[i].value = value;
			return;
		}
	error("Set: undefined name ", name);
}

//Check if a variable already exists
bool Symbol_Table::is_declared(string name)
{
	for (int i = 0; i < var_table.size(); i++)
		if (var_table[i].name == name)
			return true;
	return false;
}

//Declare a new variable and put it on the vector
double Symbol_Table::declare(string name, double value, bool b)
{
	if (is_declared(name))
		error(name, " is already declared");
	var_table.push_back(Variable(name, value, b));

	return value;
}

//Global instances
Token_stream ts;
Symbol_Table st;

//provide expression() and faculty_calculation() for primary()
double expression();

int factorial_calculation(double d);

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error("'(' expected");
		return d;
	}
	case 'k':
		return kvalue;
	case '-':
		return -primary();
	case sqrtchar:
	{
		t = ts.get();
		if (t.kind != '(')
			error("'(' expected");
		double d = expression();
		if (d < 0)
			error("Number lower than 0");
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		return sqrt(d);
	}
	case powchar:
	{
		t = ts.get();
		if (t.kind != '(')
			error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ',')
			error("',' expected");
		t = ts.get();
		if (t.kind != numberchar)
			error("2nd argument isn't a number");
		int i = int(t.value);
		if (i != t.value)
			error("2nd argument isn't an integer");
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		return pow(d, i);
	}
	case facultychar:
		//the resulting 0 doesn't look beautiful
	case numberchar:
	{
		Token t2 = ts.get();
		if (t2.kind == facultychar)
		{ //It somehow works without ungetting t2
			return factorial_calculation(t.value);
		}
		ts.unget(t2);
		return t.value;
	}
	case namechar:
	{
		Token t2 = ts.get();
		//Handle Assignment operation
		if (t2.kind == assignmentchar)
		{
			double d = expression();
			st.set(t.name, d);
			return d;
		}
		else
		{
			ts.unget(t2);
			return st.get(t.name);
		}
	}
	default:
		error("primary expected");
	}

	return 0;
}

double term()
{
	double left = primary();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0)
				error("%: divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration(bool b)
{
	Token t = ts.get();
	if (t.kind != 'a')
		error("name expected in declaration");
	string name = t.name;
	if (st.is_declared(name))
		error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of ", name);
	double d = expression();
	st.declare(name, d, b);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case letchar:
		return declaration(false);
	case constchar:
		return declaration(true);
	default:
		ts.unget(t);
		return expression();
	}
}

int factorial_calculation(double d)
{
	// int faculty = d;
	int faculty = narrow_cast<int>(d);
	if (d < 0)
		error("Only positive integers are allowed");
	if (d == 0 || d == 1)
		return 1;
	for (int i = d - 1; i >= 2; i--)
		faculty *= i;
	return faculty;
}

void show_help()
{
	cout << "help\t\t\tprint this help menu\n"
		 << "let <name>=<number>\tdeclare a new non-constant variable\n"
		 << "const <name>=<number>\tdeclare a new constant variable\n"
		 << "pow(<a>,<n>)\t\tcalculate the nth power to a\n"
		 << "sqrt(<number>)\t\tcalculate the squareroot of <number>\n"
		 << "!<number>\t\tcalculate the factorial of an integer\n"
		 << "quit\t\t\tquit the program\n";
}

void clean_up_mess()
{
	ts.ignore(printchar);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true)
	{
		try
		{
			cout << prompt;
			Token t = ts.get();
			while (t.kind == printchar)
				t = ts.get();
			if (t.kind == helpchar)
				show_help();
			else
			{
				if (t.kind == quitchar)
					return;
				ts.unget(t);
				cout << result << statement() << endl;
			}
		}
		catch (runtime_error &e)
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}
	}
}

int main()
{
	try
	{
		calculate();
		return 0;
	}
	catch (exception &e)
	{
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';')
			return 1;
	}
	catch (...)
	{
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';')
			return 2;
	}
}
