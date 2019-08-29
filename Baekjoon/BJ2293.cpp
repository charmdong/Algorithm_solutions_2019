/// Dynamic Programming : µ¿Àü 1

#include <iostream>
using namespace std;

int value[101];
int dp[101][10001];
int solution(int n, int k);

int dp2[10001];
int solution2(int n, int k);

int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		cin >> value[i+1];

	//cout << solution(n, k) << endl;
	cout << solution2(n, k) << endl;
	return 0;
}

int solution(int n, int k) {
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= value[i])
				dp[i][j] = dp[i - 1][j] + dp[i][j - value[i]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][k];
}

int solution2(int n, int k) {
	dp2[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= value[i])
				dp2[j] += dp2[j - value[i]];
			cout << dp2[j] << endl;
		}
	}
	return dp2[k];
}