/// 동적 계획법 - 1로 만들기

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
		// 2,3의 배수인 경우 각각 2와 3으로 나눈 수의 dp값 + 1로 나타낼 수 있음.
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
}