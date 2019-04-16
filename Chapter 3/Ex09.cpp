#include "std_lib_facilities.h"

int main(){
        string str = "";

        cin>>str;

        if(str == "zero")
                cout << 0;
        else if(str == "one")
                cout << 1;
        else if(str == "two")
                cout << 2;
        else if(str == "three")
                cout << 3;
        else if(str == "four")
                cout << 4;
        else
                cout << "not a number i know.\n";
}
