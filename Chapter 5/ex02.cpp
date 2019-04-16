#include <std_lib_facilities.h>

double ctok(double c)
{
    if (c < -273.15)
        error("Number too low!");

    double k = c + 273.15;

    return k;
}

double ktoc(double k)
{
    if (k < 0)
        error("Number too low!");

    double c = k - 273.15;

    return c;
}

int main()
{
    double result = 0;
    double degree = 0;
    int choice;

    cout << "1: celsius to kelvin\n2: kelvin to celsius\nNumber: ";
    cin >> choice;
    cout << "Degree: ";
    cin >> degree;

    if (choice == 1)
        result = ctok(degree);
    else if (choice == 2)
        result = ktoc(degree);

    cout << result << '\n';
}
