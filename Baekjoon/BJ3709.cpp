/**
 * @author : donggun.chung
 * @date : 2020.02.17
 * @site : BOJ
 * @prob_Info : 3709 레이저빔은 어디로 
 * @time : 0ms
 * @memory : 2124KB
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, n, r;
vector<vector<int>> board;
bool visited[51][51][4];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

pair<int, int> solution(int sy, int sx);
bool isInBoard(int y, int x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int test = 1; test <= T; test++) {
		cin >> n >> r;

		board.assign(n + 2, vector<int>(n + 2, 0));
		memset(visited, false, sizeof(visited));

		int row, col, sy, sx;
		for (int iter = 0; iter < r; iter++) {
			cin >> row >> col;

			board[row][col] = 1;
		}

		cin >> sy >> sx;

		pair<int, int> res = solution(sy, sx);
		cout << res.first << " " << res.second << endl;
	}

	return 0;
}

pair<int, int> solution(int sy, int sx) {
	int dir;

	// 레이저 위치 기준으로 레이저 발사 방향 정하기
	if (sy > n) {
		dir = 0;
	}
	else if (sx < 1) {
		dir = 1;
	}
	else if (sy < 1) {
		dir = 2;
	}
	else {
		dir = 3;
	}

	int ny = sy + dy[dir];
	int nx = sx + dx[dir];

	while (isInBoard(ny, nx)) {
		if (board[ny][nx] == 1) {
			if (!visited[ny][nx][dir]) {
				visited[ny][nx][dir] = true;
				dir = (dir + 1) % 4;
			}
			else {
				ny = nx = 0;
				break;
			}
		}
		ny += dy[dir];
		nx += dx[dir];
	}

	return make_pair(ny, nx);
}

bool isInBoard(int y, int x) {
	return (y > 0 && y <= n && x > 0 && x <= n);
}