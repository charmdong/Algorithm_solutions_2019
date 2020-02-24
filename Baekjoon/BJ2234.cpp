/**
 * @author : donggun.chung
 * @date : 2020.02.22
 * @site : BOJ
 * @prob_Info : 2234 성곽 
 * @time : 128ms
 * @memory : 2124KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, maxValue;
int part, area;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1 ,0 };

int bfs(int row, int col);
int removeWall(int row, int col);
int bfs(vector<vector<int>> board, int row, int col);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n;

	board.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, false));

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> board[row][col];
		}
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			if (!visited[row][col]) {
				int res = bfs(board, row, col);

				if (area < res) {
					area = res;
				}
				part++;
			}
		}
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			int res = removeWall(row, col);

			if (maxValue < res) maxValue = res;
		}
	}

	cout << part << endl;
	cout << area << endl;
	cout << maxValue << endl;

	return 0;
}

int bfs(int row, int col) {
	int answer = 0;
	queue<pair<int, int>> q;

	visited[row][col] = true;
	q.push({ row, col });

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		answer++;

		for (int dir = 0; dir < 4; dir++) {
			if ((board[now.first][now.second] & (1 << dir)) == 0) {
				int ny = now.first + dy[dir];
				int nx = now.second + dx[dir];
				
				if (ny > -1 && ny < n && nx > -1 && nx < m) {
					if (!visited[ny][nx]) {
						visited[ny][nx] = true;
						q.push({ ny, nx });
					}
				}
			}
		}
	}

	return answer;
}

int removeWall(int row, int col) {
	int answer = 0;
	vector<vector<int>> tmp = board;
	
	for (int dir = 0; dir < 4; dir++) {
		if ((board[row][col] & (1 << dir)) != 0) {
			int ny = row + dy[dir];
			int nx = col + dx[dir];

			if (ny > -1 && ny < n && nx > -1 && nx < m) {
				int before = tmp[row][col];
				tmp[row][col] ^= (1 << dir);
				//cout << board[row][col] << ", " << tmp[row][col] << endl;
				int res = bfs(tmp, row, col);
				if (answer < res) {
					answer = res;
				}
				tmp[row][col] = before;
			}
		}
	}

	return answer;
}

int bfs(vector<vector<int>> board, int row, int col) {
	int answer = 0;
	visited.assign(n, vector<bool>(m, false));
	
	queue<pair<int, int>> q;

	visited[row][col] = true;
	q.push({ row, col });

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		answer++;

		for (int dir = 0; dir < 4; dir++) {
			if ((board[now.first][now.second] & (1 << dir)) == 0) {
				int ny = now.first + dy[dir];
				int nx = now.second + dx[dir];

				if (ny > -1 && ny < n && nx > -1 && nx < m) {
					if (!visited[ny][nx]) {
						visited[ny][nx] = true;
						q.push({ ny, nx });
					}
				}
			}
		}
	}

	return answer;
}