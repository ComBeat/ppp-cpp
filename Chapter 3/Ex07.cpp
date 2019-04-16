#include "std_lib_facilities.h"

int main(){
    string n1, n2, n3;

    cin >> n1 >> n2 >> n3;

    if(n1 < n2 && n1 < n3){
        cout << n1 << ", ";
        if(n2 < n3)
            cout << n2 << ", " << n3;
        else
            cout << n3 << ", " << n2;
    } else if(n2 < n1 && n2 < n3){
        cout << n2 << ", ";
        if(n1 < n3)
            cout << n1 << ", " << n3;
        else
            cout << n3 << ", " << n1;
    } else if(n3 < n1 && n3 < n2){
        cout << n3 << ", ";
        if(n1 < n2)
            cout << n1 << ", " << n2;
        else
            cout << n2 << ", " << n1;
    }
}
