#include "patron.h"

namespace Patron
{
Patron::Patron()
    : surname{""}, prename{""}, card_number{0}, library_fees{0.0} {
}

Patron::Patron(string sname, string pname, int cnumber, double fees)
    : surname{sname}, prename{pname}, card_number{cnumber} {
    if (fees >= 0.0)
        library_fees = fees;
    else
        error("Library fees can't be negative");
}

bool Patron::owes_fee() {
    if (library_fees > 0.0)
        return true;
    else
        return false;
}

void Patron::adjust_library_fees(double fee_new) {
    if (library_fees + fee_new >= 0.0)
        library_fees += fee_new;
    else
        error("Invalid fee");
}
}  // namespace Patron
