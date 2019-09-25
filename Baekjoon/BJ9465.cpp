#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

vector<vector<int>> dp;

int solution(int n, vector<vector<int>> board);

int main()
{
	int t, n;
	cin >> t;

	while(t--) {
		vector<vector<int>> board;

		cin >> n;

		board.assign(2, vector<int>(n + 1, 0));
		dp.assign(2, vector<int>(n + 1, 0));

		for(int row = 0; row < 2; row++) {
			for(int col = 1; col <= n; col++) {
				cin >> board[row][col];
			}
		}

		cout << solution(n, board) << endl;
	}

	return 0;
}

int solution(int n, vector<vector<int>> board) {
	int answer = 0;

	dp[0][0] = dp[1][0] = 0;
	dp[0][1] = board[0][1];
	dp[1][1] = board[1][1];

	for(int index = 2; index <= n; index++) {
		dp[0][index] = max(dp[1][index - 1], dp[1][index - 2]) + board[0][index];
		dp[1][index] = max(dp[0][index - 1], dp[0][index - 2]) + board[1][index];
	}

	answer = max(dp[0][n], dp[1][n]);
	return answer;
}