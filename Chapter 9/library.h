#include "../std_lib_facilities.h"
#include "book.h"
#include "chrono.h"
#include "patron.h"

namespace Library
{
class Library
{
    struct Transaction
    {
        Book::Book     book;
        Patron::Patron patron;
        Chrono::Date   date;

        Transaction(Book::Book book, Patron::Patron patron, Chrono::Date date)
            : book{book}, patron{patron}, date{date} {}
    };

    vector<Book::Book>     books;
    vector<Patron::Patron> patrons;
    vector<Transaction>    transactions;

  public:
    void                   add_book(Book::Book);
    void                   add_patron(Patron::Patron);
    void                   check_out_book(Book::Book, Patron::Patron, Chrono::Date);
    bool                   owes_fees(Patron::Patron);
    vector<Patron::Patron> owing_fees();
};
}  // namespace Library
