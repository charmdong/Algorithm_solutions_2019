// You can also solve this problem by using dfs algorithm.
#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int n, m;
int map[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			dp[i][j] = map[i][j] + max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}