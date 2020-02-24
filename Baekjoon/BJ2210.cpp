/**
 * @author : donggun.chung
 * @date : 2020.02.18
 * @site : BOJ
 * @prob_Info : 2210 숫자판 점프 
 * @time : 0ms
 * @memory : 3360KB
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int answer;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<vector<int>> board(5, vector<int>(5, 0));
set<int> result;

void solution();
void dfs(int curY, int curX, int res, int cnt = 0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			cin >> board[row][col];
		}
	}

	solution();

	return 0;
}

void solution() {
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			dfs(row, col,  board[row][col]);
		}
	}

	cout << result.size() << endl;
}

void dfs(int curY, int curX, int res, int cnt) {
	if (cnt == 5) {
		result.insert(res);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int ny = curY + dy[dir];
		int nx = curX + dx[dir];

		if (ny > -1 && ny < 5 && nx > -1 && nx < 5) {
			dfs(ny, nx, res * 10 + board[ny][nx], cnt + 1);
		}
	}
}