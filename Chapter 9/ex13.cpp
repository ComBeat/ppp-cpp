#include "ex13.h"

#include "../std_lib_facilities.h"

namespace Rational
{
Rational::Rational(int n, int d) {
    if (d != 0)
        denominator = d;
    else
        error("Denominator cannot be 0");
}

Rational operator+(const Rational &r0, const Rational &r1) {
	//doesn't handle different denominators yet
    Rational rat{r0.get_numerator() + r1.get_numerator(), r0.get_denominator()};

    return rat;
}
}  // namespace Rational
