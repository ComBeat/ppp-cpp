#include "std_lib_facilities.h"

int main(){
    double value;
    char unit;

    cout << "Please enter a value and a currency (y/k/p): ";
    cin >> value >> unit;

    if(unit == 'y')
        cout << "y == " << value * 0.0094 << " dollar.\n";
    else if(unit == 'k')
        cout << "k == " << value * 0.17 << " dollar.\n";
    else if(unit == 'p')
        cout << "p == " << value * 1.4 << " dollar.\n";
    else
        cout << "Fuck off.\n";
}
