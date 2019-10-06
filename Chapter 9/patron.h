#include "../std_lib_facilities.h"

namespace Patron
{
class Patron
{
    string surname;
    string prename;
    int    card_number;
    double library_fees;

  public:
    Patron();
    Patron(string, string, int, double);

    bool owes_fee();

    string get_surname() { return surname; }
    void   set_surname(string sname) { surname = sname; }
    string get_prename() { return prename; }
    void   set_prename(string pname) { prename = pname; }
    int    get_card_number() { return card_number; }
    double get_library_fees() { return library_fees; }
    void   set_library_fees(double fees) { library_fees = fees; }
};
}  // namespace Patron
