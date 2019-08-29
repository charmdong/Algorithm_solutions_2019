#include <iostream>
using namespace std;

int test;

int main()
{
	cin >> test;
	for (int i = 1; i <= test; i++) {
		int total = 0;
		int tmp;
		for (int j = 0; j < 10; j++) {
			cin >> tmp;
			if (tmp % 2 == 1)
				total += tmp;
		}
		cout << "#" << i << " " << total << endl;
	}
	return 0;
}