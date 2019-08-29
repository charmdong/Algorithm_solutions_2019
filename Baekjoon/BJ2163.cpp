#include <iostream>
#define MAX 300
using namespace std;

int n, m;
int dp[MAX + 1][MAX + 1];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dp[i][1] = i - 1;
		for (int j = 2; j <= m; j++)
			dp[i][j] = dp[i][j - 1] + i;
	}

	cout << dp[n][m] << endl;

	return 0;
}