#include "../std_lib_facilities.h"

void print_vector(const vector<string>& v) {
    for (string s : v) {
        cout << s << endl;
    }
}

vector<string> split(const string& s) {
    istringstream  iss{s};
    string         s2 = "";
    vector<string> v  = {};

    // for (char c : s) {
    //     if (c == s[s.size() - 1])
    //         v.push_back(s2);
    //     if (!isspace(c) /* || c == s[s.size() - 1] */) {
    //         s2 += c;
    //         continue;
    //     } else {
    //         v.push_back(s2);
    //         s2 = "";
    //     }
    // }

    // istringstream automatically seperates at whitespace
    while (iss >> s2) v.push_back(s2);

    return v;
}

int main() {
    string phrase = "";
    cout << "Please enter some string: ";
    getline(cin, phrase);
    vector<string> newphrase = split(phrase);
    print_vector(newphrase);
}
