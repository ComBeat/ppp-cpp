#include <std_lib_facilities.h>

//Calculate the discriminant
double Discriminant(int a, int b, int c)
{
	double discr = ((b * b) - (4 * a * c));

	if (discr < 1)
		error("Discriminant is too low.");

	return sqrt(discr);
}

int main()
{
	double x1, x2;
	int a = 1, b = 3, c = -4;

	cout << "Please enter your a, b, and c: ";
	cin >> a, b, c;

	//Solve the quadratic equation and print the results
	x1 = (-b + Discriminant(a, b, c)) / 2 * a;
	x2 = (-b - Discriminant(a, b, c)) / 2 * a;

	cout << "x1: " << x1 << endl;
	cout << "x2: " << x2 << endl;
}
