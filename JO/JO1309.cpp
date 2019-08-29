#include <iostream>
using namespace std;

long long factorial(int n);

int main()
{
		int n;
		cin >> n;
		cout << factorial(n) << "\n";
		return 0;
}

long long factorial(int n) {
		if (n == 0) return 1;

		long long ret = n;
		if (n != 1)
				cout << n << "! = " << n << " * " << n - 1 << "!\n";
		else
				cout << n << "! = " << n << "\n";
		return ret * factorial(n - 1);
}