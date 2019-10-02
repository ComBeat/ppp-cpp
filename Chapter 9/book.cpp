#include "book.h"

namespace Book {
bool operator==(const string &isbn1, const string &isbn2) {
    return isbn1 == isbn2;
}

bool operator!=(const string &isbn1, const string &isbn2) {
    return !(isbn1 == isbn2);
}

ostream &operator<<(ostream &os, const Book &book) {
    return os << "\nTitle: " << book.get_title()
              << "\nAuthor: " << book.get_author()
              << "\nISBN: " << book.get_isbn();
}

Book::Book() : isbn{"0-0-0-0"}, title{""}, author{""}, cp_date{""} {}

Book::Book(int isbn1, int isbn2, int isbn3, char isbn4, string title, string author, string cp_date) {
    set_isbn(isbn1, isbn2, isbn3, isbn4);
    set_title(title);
    set_author(author);
    set_cp_date(cp_date);
}

bool Book::isbn_validity(const string &to_check) {
    int dash_counter = 0;

    for (int i = 0; i < to_check.size(); i++) {
        char ch_to_check = to_check.at(i);

        if (ch_to_check == '-') {
            dash_counter++;
            continue;
        }
        if (dash_counter != 3 && (ch_to_check < '0' || ch_to_check > '9')) {
            error("ISBN has wrong format!");
            return false;
        } else if ((ch_to_check < 'A' || ch_to_check > 'Z') &&
                   (ch_to_check < 'a' || ch_to_check > 'z')) {
            error("Last block isn't a digit or letter!");
            return false;
        }
        if (dash_counter == 3 &&
            to_check.at(i + 1) !=
                NULL) {  // use char as parameter and append it then
            error("Too many chars in last block!");
            return false;
        }
    }
    return true;
}

void Book::set_isbn(int isbn1, int isbn2, int isbn3, char isbn4) {
    isbn = isbn1 << '-' << isbn2 << '-' << isbn3 << '-' << isbn4;
}
}  // namespace Book
