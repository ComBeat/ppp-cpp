#include "std_lib_facilities.h"

int main(){
    int val1, val2;

    cout << "Please enter val: ";
    cin >> val1;
    cout << "Please enter val2: ";
    cin >> val2;

    if(val1 == val2){
        cout << "\nval1 and val2 are the same";
    } else if(val1 < val2){
        cout << "\nval1 is smaller than val2";
    } else{
        cout << "\nval2 is smaller than val1";
    }

    cout << "\n\nsum: " << val1 + val2;
    cout << "\ndifference: " << val1 - val2;
    cout << "\nproduct: " << val1 * val2;
    cout << "\nquotient: " << val1 / val2;
}
