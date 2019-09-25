#include "../std_lib_facilities.h"

class Book
{
	Book();
	Book(string isbn, string title, string author, string cp_date);

	string isbn;
	string title;
	string author;
	string cp_date;
	bool checked_in;
	bool isbn_validity(string);

public:
	void set_checkin_status(bool);
	bool get_checkin_status() { return checked_in; }
	void set_isbn(string);
	string get_isbn() { return isbn; }
	void set_title(string);
	string get_title() { return title; }
	void set_author(string);
	string get_author() { return author; }
	void set_cp_date(string);
	string get_cp_date() { return cp_date; }
};

Book::Book() : isbn{""}, title{""}, author{""}, cp_date{""}
{
}

Book::Book(string isbn, string title, string author, string cp_date)
{
	if (isbn_validity(isbn))
		set_isbn(isbn);

	set_title(title);
	set_author(author);
}
