#include "ex13.h"

namespace Rational
{
Rational::Rational(int n, int d) {
    if (d != 0)
        denominator = d;
    else
        error("Denominator cannot be 0");
}

Rational operator+(const Rational &r0, const Rational &r1) {
    Rational rat;

    if (r0.get_denominator() == r1.get_denominator())
        rat = Rational{r0.get_numerator() + r1.get_numerator(), r0.get_denominator()};
    else
        rat = Rational{r0.get_numerator() * r1.get_denominator() + r1.get_numerator() * r0.get_denominator(), r0.get_denominator() * r1.get_denominator()};

    return rat;
}

Rational operator-(const Rational &r0, const Rational &r1) {
    Rational rat;

    if (r0.get_denominator() == r1.get_denominator())
        rat = Rational{r0.get_numerator() - r1.get_numerator(), r0.get_denominator()};
    else
        rat = Rational{r0.get_numerator() * r1.get_denominator() - r1.get_numerator() * r0.get_denominator(), r0.get_denominator() * r1.get_denominator()};

    return rat;
}

Rational operator*(const Rational &r0, const Rational &r1) {
    return Rational{r0.get_numerator() * r1.get_numerator(), r0.get_denominator() * r1.get_denominator()};
}

Rational operator/(const Rational &r0, const Rational &r1) {
    return Rational{r0.get_numerator() * r1.get_denominator(), r0.get_denominator() * r1.get_numerator()};
}

bool operator==(const Rational &r0, const Rational &r1) {
    return (r0.get_numerator() == r1.get_numerator()) && (r0.get_denominator() == r1.get_denominator());
}
}  // namespace Rational
