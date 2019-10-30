#include "ex13.h"

using namespace Rational;

int main() {
    Rational::Rational r0{6, 8};
    Rational::Rational r1{3, 4};
    Rational::Rational radd  = r0 + r1;
    Rational::Rational rsub  = r0 - r1;
    Rational::Rational rmult = r0 * r1;
    Rational::Rational rdiv  = r0 / r1;
    string             eq    = (r0 == r1) ? "true" : "false";

    cout << "r0: " << r0.get_numerator() << ' ' << r0.get_denominator() << endl;
    cout << "r1: " << r1.get_numerator() << ' ' << r1.get_denominator() << endl;
    cout << "add: " << radd.get_numerator() << ' ' << radd.get_denominator() << endl;
    cout << "sub: " << rsub.get_numerator() << ' ' << rsub.get_denominator() << endl;
    cout << "mult: " << rmult.get_numerator() << ' ' << rmult.get_denominator() << endl;
    cout << "div: " << rdiv.get_numerator() << ' ' << rdiv.get_denominator() << endl;
    cout << "equal: " << eq << endl;
}
