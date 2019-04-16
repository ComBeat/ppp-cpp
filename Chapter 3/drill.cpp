#include "std_lib_facilities.h"

int main()
{
    //Letter to friend
    cout << "Enter the name of the person you want to write to: ";
    string first_name;    // first_name is a variable of type string
    cin >> first_name;    // read characters into first_name
    cout << "\nDear " << first_name << ",\n";
    cout << "\nHow are you? I am fine.\nI miss you.\n";
    cout << "I don't really know what else to write.";

    //Another friend
    string friend_name = "";

    cout << "\n\n//Enter the name of another friend: ";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?";
    char friend_sex = '0';
    cout << "\n\n//Sex of your friend (m/f): ";
    cin >> friend_sex;

    if(friend_sex == 'm'){
        cout << "If you see " << friend_name << " please ask him to call me.";
    } else if(friend_sex == 'f'){
        cout << "If you see " << friend_name << " please ask her to call me.";
    }

    //Age of the recipient
    cout << "\n\n//Age of the recipient: ";
    int age = 0;
    cin >> age;
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    if(age <= 0 || age >= 110){
        simple_error("you're kidding!");
    } else if(age < 12){
        cout << "Next year you will be " << ++age << '.';
    } else if(age == 17){
        cout << "Next your you will be able to vote";
    } else if(age > 70){
        cout << "I hope you are enjoying retirement.";
    }

    cout << "\n\nYours sincerely,";
    cout << "\n\n\nYannik";
}
