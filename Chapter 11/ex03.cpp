#include "../std_lib_facilities.h"

int main() {
    string   inputfile = "text_files/ex02_input.txt";
    ifstream ifs{inputfile};

    if (!ifs) error("Couldn't open input file: ", inputfile);

    // Still prints 2 or more consecutive space chars
    char ch;
    while (ifs.get(ch)) {
        char ch_lower = tolower(ch);

        switch (ch_lower) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': break;
            default: cout << ch;
        }
    }
    cout << endl;
}
