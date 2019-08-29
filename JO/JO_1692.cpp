#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void input();
void res(int, string);

int main()
{
		input();
		return 0;
}

void input() {
		int n1;
		string n2;
		cin >> n1 >> n2;
		res(n1, n2);
}

void res(int n1, string n2) {
		int size = n2.length();
		int total = 0;

		for (int i = size - 1; i >= 0; i--) {
				int tmp = n1 * (n2[i] - '0');
				cout << tmp << endl;
				total += tmp * pow(10, size - 1 - i);
		}

		cout << total << endl;
}