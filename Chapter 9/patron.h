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
};
}  // namespace Patron
