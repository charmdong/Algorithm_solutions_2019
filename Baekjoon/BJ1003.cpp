/// 동적 계획법 - 피보나치 함수 (메모이제이션)
/// base case 0,1은 n번째 피보나치 수에 대해서 각각 fibonacci(n-1), fibonacci(n)번씩 나타난다.
/// n==0 일 때는 각각 1, 0번

#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int num;
		cin >> num;
		if (num == 0)
			cout << "1 0\n";
		else
			cout << fibonacci(num - 1) << " " << fibonacci(num) << '\n';
	}
	return 0;
}

int fibonacci(int n) {
	static int memo[41] = { 0 };
	
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	if (memo[n] > 0) return memo[n];

	return memo[n] = fibonacci(n - 2) + fibonacci(n - 1);
}