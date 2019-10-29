#include "../std_lib_facilities.h"

namespace Rational
{
class Rational
{
    int numerator;
    int denominator;

  public:
    Rational()
        : numerator(0), denominator(1){};
    Rational(int n, int d);
    double to_double() { return numerator / denominator; }
    int    get_numerator() const { return numerator; }
    int    get_denominator() const { return denominator; }
};

Rational operator+(const Rational, const Rational);
Rational operator-(const Rational, const Rational);
Rational operator*(const Rational, const Rational);
Rational operator/(const Rational, const Rational);
bool operator==(const Rational, const Rational);
}  // namespace Rational
