#include "../std_lib_facilities.h"

namespace Book {
class Book {
    int isbn1;
    int isbn2;
    int isbn3;
    char isbn4;
    string isbn;
    string title;
    string author;
    string cp_date;
    bool checked_in;

    Book();
    Book(int isbn1, int isbn2, int isbn3, char isbn4, string title, string author, string cp_date);
    enum Genre {
        fiction,
        nonfiction,
        periodical,
        biography,
        children
    };

    bool isbn_validity(const string &str);

   public:
    void set_checkin_status(bool);
    bool get_checkin_status() const { return checked_in; }
    void set_isbn(int, int, int, char);
    string get_isbn() const { return isbn; }
    void set_title(string t) { title = t; }
    string get_title() const { return title; }
    void set_author(string a) { author = a; }
    string get_author() const { return author; }
    void set_cp_date(string d) { cp_date = d; }
    string get_cp_date() const { return cp_date; }
};

bool operator==(const string &isbn1, const string &isbn2);

bool operator!=(const string &isbn1, const string &isbn2);

ostream &operator<<(ostream &os, const Book &book);
}  // namespace Book
