/*
!(not)
~(complement)
&(and)
|(or)
^(exclusive or)

prefix unary:
  !
  ~

& > ^ > |
*/

#include "../std_lib_facilities.h"

vector<int> bitarr;

class prefix
{
public:
	char pretok;
	int bittok;
	Token(char ch, int val)
		: kind(ch), value(val)
	{
	}
};

class prefix_stream
{
public:
	prefix_stream();
	prefix get();
	void putback(prefix p);

private:
	bool full;
	prefix buffer;
};

prefix_stream::prefix_stream()
	: full(false), buffer(0) {}

void prefix_stream::putback(prefix p)
{
	if (full)
		error("putback() into a full buffer\n");
	buffer = p;
	full = true;
}
