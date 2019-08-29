#include <iostream>
using namespace std;

int solution(int a, int b);

int main()
{
	int t;
	int a, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << solution(a, b) << endl;
	}
	return 0;
}

int solution(int a, int b) {
	int gcd=1;

	int small = (a > b) ? b : a;

	for (int i = small; i >= 2; i--) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
			break;
		}
	}

	return a * b / gcd;
}