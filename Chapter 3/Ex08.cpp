#include "std_lib_facilities.h"

int main(){
    int n1;

    cin >> n1;

    if(n1 % 2 == 0)
        cout << "The value " << n1 << " is an even number.\n";
    else
        cout << "The value " << n1 << " is not an even number.\n";
}
