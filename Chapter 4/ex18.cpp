#include <std_lib_facilities.h>

int main()
{
    int a;
    int b;
    int c;
    double x1;
    double x2;
    double discr = 0;

    do
    {
        cout << "Enter a, b and c: ";
        cin >> a >> b >> c;

        //calculate discriminant
        discr = b * b - 4 * a * c;
        if(discr < 0)
            cout << "WTF?!\n\n";
    } while (discr <= 0);

    x1 = (-b + sqrt(discr)) / (2 * a);
    x2 = (-b - sqrt(discr)) / (2 * a);

    cout << "x1: " << x1 << "\nx2: " << x2 << '\n';
}
