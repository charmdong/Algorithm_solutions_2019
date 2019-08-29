/// ���� ��ȹ�� - �Ǻ���ġ �Լ� (�޸������̼�)
/// base case 0,1�� n��° �Ǻ���ġ ���� ���ؼ� ���� fibonacci(n-1), fibonacci(n)���� ��Ÿ����.
/// n==0 �� ���� ���� 1, 0��

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