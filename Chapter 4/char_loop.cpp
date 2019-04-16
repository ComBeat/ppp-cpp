#include "std_lib_facilities"

int main(){
    char letter = 'a';

    for(int i = letter; i <= 'z'; i++){
        cout << letter << "\t" << i << "\n";
        letter++;
    }
}
