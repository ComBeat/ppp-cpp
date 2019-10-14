#include "library.h"

namespace Library
{
void Library::add_book(Book::Book book_new) {
    books.push_back(book_new);
}

void Library::add_patron(Patron::Patron patron_new) {
    patrons.push_back(patron_new);
}

bool Library::owes_fees(Patron::Patron patron) {
    if (patron.get_library_fees() > 0.0) {
        return true;
    }
    return false;
}

void Library::check_out_book(Book::Book book, Patron::Patron patron, Chrono::Date date) {
    if (!(find(books.begin(), books.end(), book) != books.end()))
        error("Book does not exist!");
    if (!(find(patrons.begin(), patrons.end(), patron) != patrons.end()))
        error("Patron does not exist!");
    if (owes_fees(patron))
        error("Patron owes fees!");

    Transaction transaction{book, patron, date};
    transactions.push_back(transaction);
}

vector<Patron::Patron> Library::owing_fees() {
    vector<Patron::Patron> members;

    for (Patron::Patron patron : patrons)
        if (patron.get_library_fees() > 0.0)
            members.push_back(patron);

    return members;
}
}  // namespace Library
