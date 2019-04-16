#include "std_lib_facilities"

int main()
{
    int number;
    int result = number;

    cout << "Number: ";
    cin >> number;

    for(int i = 0; i < number; i++)
    {
        result += number;
        cout << "\nn: " << result;
    }

    cout << "\nresult: " << result;
}
