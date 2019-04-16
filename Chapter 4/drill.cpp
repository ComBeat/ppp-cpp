#include <std_lib_facilities>

int main(){
    int count = 0;
    double n1 = 0;
    double n2 = 0;
    double conv;
    double diff1;
    double diff2;
    double minnum;
    double maxnum;
    double number_n;
    double sum = 0.0;
    bool numberinput = false;
    bool extrinit = false;
    string unit;
    vector<double> values = {};

    while (cout << "Input: ", cin >> number_n >> unit){
        int i = 0;
        count++;

        //transmit value of number_n to respective variable
        if(!numberinput) n1 = number_n;
        else             n2 = number_n;

        //Check which value is smaller and which one is greater
        if (n1 < n2){
            cout << "The smaller value is n1: " << n1 << '\n';
            cout << "The greater value is n2: " << n2 << '\n';
        } else if (n2 < n1){
            cout << "The smaller value is n2: " << n2 << '\n';
            cout << "The greater value is n1: " << n1 << '\n';
        } else{
            cout << "The numbers are equal.\n";
        }

        diff1 = n1 - n2;
        diff2 = n2 - n1;

        if ((diff1 < 0.001 && diff1 > 0) ||
            (diff2 < 0.001 && diff2 > 0))
            cout << "\nThe numbers are almost equal.\n";

        if(!extrinit){
            minnum = maxnum = number_n;
            extrinit = !extrinit;
        }

        if(minnum > number_n)
            minnum = number_n;

        if(maxnum < number_n)
            maxnum = number_n;

        cout << "Smallest number so far: " << minnum << '\n';
        cout << "Largest number so far: " << maxnum << "\n\n";

        //Conversion
        if(unit == "cm"){
            conv = number_n / 100;
            sum += conv;
            values.push_back(conv);
            cout << number_n << ' ' << unit << " == " << conv << "m" << "\n\n";
        } else if(unit == "m"){
            conv = number_n * 100;
            sum += number_n;
            values.push_back(number_n);
            cout << number_n << ' ' << unit << " == " << conv << "cm" << "\n\n";
        } else if(unit == "in"){
            conv = number_n * 2.54;
            sum += conv / 100;
            values.push_back(conv);
            cout << number_n << ' ' << unit << " == " << conv << "cm" << "\n\n";
        } else if(unit == "ft"){
            conv = number_n * 12;
            sum += number_n * 0.3;
            values.push_back(conv);
            cout << number_n << ' ' << unit << " == " << conv << "in" << "\n\n";
        } else {
            cout << "Illegal unit! Please use cm, m, in or ft\n\n";
        }

        i++;

        //flip bool
        if(!numberinput) numberinput = !numberinput;
        else             numberinput = !numberinput;
    }

    cout << "Smallest number: " << minnum << '\n';
    cout << "Largest number: " << maxnum << '\n';
    cout << "Values entered: " << count << '\n';
    cout << "Sum: " << sum << 'm' << "\n";

    sort(values.begin(), values.end());

    // for(int i : values){
    //     cout << "Value " << i+1 << ": " << values[i] << "\n";
    // }

    for(int i = 0; i < values.size(); ++i){
        cout << "Value " << i+1 << ": " << values[i] << "\n";
    }
}
