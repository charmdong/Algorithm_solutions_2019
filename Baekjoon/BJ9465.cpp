#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int t, n;

int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		int dp[2][MAX + 1], v[2][MAX + 1];
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> v[i][j];
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = v[0][1]; 
		dp[1][1] = v[1][1];

		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
		}
		cout << max(dp[0][n], dp[1][n]) << endl;
	}

	return 0;
}