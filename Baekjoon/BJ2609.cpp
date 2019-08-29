#include <iostream>
using namespace std;

void solution(int a, int b);

int main()
{
	int a, b;
	cin >> a >> b;
	solution(a, b);
	return 0;
}

void solution(int a, int b) {
	int small = (a > b) ? b : a;
	int gcd=1, lcm=1;

	for (int i = small; i >= 2; i--) {
		if (a% i == 0 && b % i == 0) {
			gcd = i;
			break;
		}
	}
	lcm = a * b / gcd;

	cout << gcd << endl;
	cout << lcm << endl;	
}