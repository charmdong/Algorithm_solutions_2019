#include <iostream>
#define MAX 100

int main() 
{
	int n;
	std::cin >> n;

	long long dp[MAX][2];
	dp[1][0] = dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	std::cout << dp[n][1] << std::endl;
	return 0;
}