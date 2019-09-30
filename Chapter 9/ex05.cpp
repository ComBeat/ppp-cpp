#include "../std_lib_facilities.h"

class Book
{
	Book();
	Book(string isbn, string title, string author, string cp_date);
	enum Genre
	{
		fiction,
		nonfiction,
		periodical,
		biography,
		children
	};

	string isbn;
	string title;
	string author;
	string cp_date;
	bool checked_in;
	bool isbn_validity(const string &str);

public:
	void set_checkin_status(bool);
	bool get_checkin_status() const { return checked_in; }
	void set_isbn(string);
	string get_isbn() const { return isbn; }
	void set_title(string t) { title = t; }
	string get_title() const { return title; }
	void set_author(string a) { author = a; }
	string get_author() const { return author; }
	void set_cp_date(string d) { cp_date = d; }
	string get_cp_date() const { return cp_date; }
};

bool operator==(const string &isbn1, const string &isbn2)
{
	return isbn1 == isbn2;
}

bool operator!=(const string &isbn1, const string &isbn2)
{
	return !(isbn1 == isbn2);
}

ostream &operator<<(ostream &os, const Book &book)
{
	return os << "\nTitle: " << book.get_title()
			  << "\nAuthor: " << book.get_author()
			  << "\nISBN: " << book.get_isbn();
}

Book::Book() : isbn{"0-0-0-0"}, title{""}, author{""}, cp_date{""}
{
}

Book::Book(string isbn, string title, string author, string cp_date)
{
	if (isbn_validity(isbn))
		set_isbn(isbn);

	set_title(title);
	set_author(author);
	set_cp_date(cp_date);
}

bool Book::isbn_validity(const string &to_check)
{
	int dash_counter = 0;

	for (int i = 0; i < to_check.size(); i++)
	{
		char ch_to_check = to_check.at(i);

		if (ch_to_check == '-')
		{
			dash_counter++;
			continue;
		}
		if (dash_counter != 3 && (ch_to_check < '0' || ch_to_check > '9'))
		{
			error("ISBN has wrong format!");
			return false;
		}
		else if ((ch_to_check < 'A' || ch_to_check > 'Z') && (ch_to_check < 'a' || ch_to_check > 'z'))
		{
			error("Last block isn't a digit or letter!");
			return false;
		}
		if (dash_counter == 3 && to_check.at(i + 1) != NULL)
		{ //use char as parameter and append it then
			error("Too many chars in last block!");
			return false;
		}
	}
	return true;
}

void Book::set_isbn(string isbn_new)
{
	if (isbn_validity(isbn_new))
		isbn = isbn_new;
}
