/// Factorial

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
	int res = 1;
	for (int i = 2; i <= n; i++)
		res *= i;

	return res;
}