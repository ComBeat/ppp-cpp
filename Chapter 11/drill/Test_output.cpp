#include "../../std_lib_facilities.h"

const int birth_year = 1970;

void print_float() {
    cout << "defaultfloat:\t" << defaultfloat << 1234567.89 << endl;
    cout << "fixed:\t\t" << fixed << 1234567.89 << endl;
    cout << "scientific:\t" << scientific << 1234567.89 << endl;
}

void year_output(int year) {
    cout << "Decimal:\t" << showbase << year << endl;
    cout << "Octal:\t\t" << oct << year << endl;
    cout << "Hex:\t\t" << hex << year << endl;
}

void convert_to_binary(int number) {
    if (number > 0) {
        int bin = number % 2;
        convert_to_binary(number /= 2);
        cout << bin;
    }
}

void int_input() {
    int a, b, c, d;

    cin >> a >> oct >> b >> hex >> c >> d;  // oct/hex means that the entered nr is already in oct/hex and not that it's going to be converted
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}

int main() {
}
