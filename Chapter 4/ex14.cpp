#include <std_lib_facilities.h>

/**
 * List all prime numbers from 1 to n with the usage of the Sieve of Eratosthenes
 *
 * Bugs: -n cannot be negative or 1
 */

vector<int> primes;

void sieve_of_eratosthenes(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (primes[i] == 1)
		{
			int x = 0;

			for (int j = (i * i) + x * i; j <= n; x++)
			{
				primes[j] = 0;
				j = (i * i) + x * i;
			}
		}
	}
}

void print_primes()
{
	int numb = 0;
	for (int i = 0; i < primes.size(); i++)
		if (primes[i] == 1)
		{
			cout << "prime: " << i << endl;
			numb++;
		}
	//Show the number of primes
	cout << "\nNumber of primes: " << numb << endl;
}

int main()
{
	//For test purposes
	int n = 100;

	cout << "Please enter a number: ";
	cin >> n;
	cout << '\n';

	if (n < 2)
		error("Number is too small");

	primes.push_back(0); //Number 0
	primes.push_back(0); //Number 1

	for (int i = 2; i <= n; i++)
		primes.push_back(1);

	sieve_of_eratosthenes(n);
	print_primes();
}
