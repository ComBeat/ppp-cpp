#include "std_lib_facilities.h"

int main(){
    double value;
    char unit;

    cout << "Please enter a value and a currency (y/k/p): ";
    cin >> value >> unit;

    switch(unit){
        case 'y':
            cout << "y == " << value * 0.0094 << " dollar.\n";
            break;
        case 'k':
            cout << "k == " << value * 0.17 << " dollar.\n";
            break;
        case 'p':
            cout << "p == " << value * 1.4 << " dollar.\n";
            break;
        default:
            cout << "Fuck off.\n";
            break;
    }
}
