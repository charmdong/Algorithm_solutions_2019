#include <iostream>
#include <cstring>
#define MAX 30
using namespace std;

int n, m, q;
int dp[MAX][MAX];

int main()
{
	cin >> q;

	while (q--) {
		cin >> n >> m;

		for (int i = 1; i <= m; i++)
			dp[0][i] = 1;

		for (int i = 1; i <= n; i++) {
			dp[i][i] = 1;
			for (int j = i + 1; j <= m; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			}
		}

		cout << dp[n][m] << endl;
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}