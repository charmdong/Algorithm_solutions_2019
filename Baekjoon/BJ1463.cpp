/// ���� ��ȹ�� - 1�� �����

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001] = { 0 };
void solution(int n);

int main()
{
	int n;
	cin >> n;
	solution(n);
	cout << dp[n] << endl;

	return 0;
}

void solution(int n) {
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		// 2,3�� ����� ��� ���� 2�� 3���� ���� ���� dp�� + 1�� ��Ÿ�� �� ����.
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
}