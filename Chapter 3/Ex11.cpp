#include "std_lib_facilities.h"

int main(){
        int pennie, nickel, dime, quarter, hdollar, odollar;
        double value, dollar;
        //bool singularity = false;

        cout << "How many pennies do you have? ";
        cin >> pennie;
        cout << "How many nickels do you have? ";
        cin >> nickel;
        cout << "How many dimes do you have? ";
        cin >> dime;
        cout << "How many quarters do you have? ";
        cin >> quarter;
        cout << "How many half dollars do you have? ";
        cin >> hdollar;
        cout << "How many dollars do you have? ";
        cin >> odollar;

        if(pennie == 0 || pennie == 1)
                cout << "\nYou have " << pennie << " pennie.";
        else
                cout << "\nYou have " << pennie << " pennies.";

        cout << "\nYou have " << nickel << " nickels.";
        cout << "\nYou have " << dime << " dimes.";
        cout << "\nYou have " << quarter << " quarters.";
        cout << "\nYou have " << hdollar << " half dollars.";
        cout << "\nYou have " << odollar << " dollars.";

        //Transformation to actual value
        nickel *= 5;
        dime *= 10;
        quarter *= 25;
        hdollar *= 50;
        odollar *= 100;
        value = pennie + nickel + dime + quarter + hdollar + odollar;
        dollar = value / 100;

        cout << "\n\nThe value of all your coins is " << value << " cents or " << dollar << " dollars.";
}
