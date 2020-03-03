#include "../std_lib_facilities.h"

int main() {
    string   inputfile  = "text_files/ex01_input.txt";
    string   outputfile = "text_files/ex01_ouput.txt";
    ifstream ifs{inputfile};

    if (!ifs) error("Couldn't open input file: ", inputfile);

    ofstream ofs{outputfile};

    if (!ifs) error("Couldn't open output file: ", outputfile);

    char c;
    while (ifs.get(c)) {
        if (isupper(c))
            c = tolower(c);
        ofs << c;
    }
}
