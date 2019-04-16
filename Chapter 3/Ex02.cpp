#include "std_lib_facilities.h"

int main(){
    double km = 0, ml = 0;

    cout << "Miles to kilometres: ";
    cin >> ml;
    km = ml * 1.609;
    cout << "\n" << ml << " miles = " << km << " kilometres.\n";
}
