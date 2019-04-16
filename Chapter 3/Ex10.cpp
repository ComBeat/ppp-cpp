#include "std_lib_facilities.h"

int main(){
        char operation = ' ';
        double n1, n2;

        cin >> operation >> n1 >> n2;

        switch(operation){
            case '+':
                cout << n1 + n2;
                break;
            case '-':
                cout << n1 - n2;
                break;
            case '*':
                cout << n1 * n2;
                break;
            case '/':
                cout << n1 / n2;
                break;
            default:
                cout << "invalid input";
                break;
        }
}
