/// ÇÑ¼ö

#include <iostream>
using namespace std;

int solution(int n);

int main()
{
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}

int solution(int n) {
	if (n < 100)
		return n;

	int res = 99;

	for (int i = 100; i <= n; i++) {
		int a, b, c;
		a = i;

		c = a % 10;
		a /= 10;
		b = a % 10;
		a /= 10;

		if (a - b == b - c)res++;
	}

	return res;
}