#include <iostream>
#define MOD 1000000000
using namespace std;

long dp[101][10];

long solution(int n);

int main()
{
	int n;

	cin >> n;
	cout << solution(n) << endl;

	return 0;
}

long solution (int n) {
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= 9; j++) {
			dp[i][j] = 0;

			if(j > 0) { // 1 ~ 9
				dp[i][j] += dp[i - 1][j - 1];
			}

			if(j < 9) { // 0 ~ 8
				dp[i][j] += dp[i - 1][j + 1];
			}

			dp[i][j] %= MOD;
		}
	}

	long ans = 0;
	for(int i = 0; i <= 9; i++) {
		ans = (ans + dp[n][i]) % MOD;
	}

	return ans;
}