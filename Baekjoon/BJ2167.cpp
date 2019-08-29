#include <iostream>
#define MAX 300
using namespace std;

int n, m, t;
int map[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];
int solution(pair<int, int> start, pair<int, int> end);

int main()
{
	pair<int, int> start, end;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			dp[i][j] = map[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	cin >> t;
	while (t--) {
		cin >> start.first >> start.second >> end.first >> end.second;
		cout << solution(start, end) << endl;
	}
	return 0;
}

int solution(pair<int ,int> s, pair<int ,int> e) {
	return dp[e.first][e.second] - dp[s.first - 1][e.second] - dp[e.first][s.second - 1] + dp[s.first - 1][s.second - 1];
}