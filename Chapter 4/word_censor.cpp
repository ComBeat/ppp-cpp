#include "std_lib_facilities"

int main()
{
    vector<string> v;
    string blocked1 = "broccoli";
    string blocked2 = "Broccoli";

    for (string str; cin >> str; ) v.push_back(str);
    for (int i = 0; i < v.size(); ++i){
        if (v[i] == blocked1)
            cout << "BEEP\n";
        else if(v[i] == blocked2)
            cout << "BEEP\n";
        else
            cout << v[i] << '\n';
    }
}
