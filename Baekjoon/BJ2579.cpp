/// Dynamic Programming : ��� ������

#include <iostream>
#include <algorithm>
using namespace std;

int stairs[301] = { 0 };
int dp[301] = { 0 };
int solution(int n);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> stairs[i + 1];
	cout << solution(n) << endl;
	
	return 0;
}

int solution(int n) {
	dp[0] = stairs[0];
	dp[1] = max(stairs[0] + stairs[1], stairs[1]);
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i <= n; i++)
		dp[i] = max(stairs[i] + dp[i - 2], stairs[i] + stairs[i - 1] + dp[i - 3]);
	// ������ ĭ�� �ݵ�� ��ƾ��ϱ� ������ ������ ĭ�� �������� �����غ���.
	return dp[n];
}