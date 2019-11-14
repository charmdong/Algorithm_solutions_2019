#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int n, m, t;
vector<vector<int>> original;
vector<pair<int, int>> fresher;

int solution();
void extension();
void circulation(int cy, int cx, int*);

int main()
{
	cin >> n >> m >> t;

	original.assign(n, vector<int>(m, 0));

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> original[row][col];

			if (original[row][col] == -1) {
				fresher.push_back({ row, col });
			}
		}
	}

	cout << solution() << endl;

	return 0;
}

int solution() {
	int answer = 0;
	int clock[4] = { 2, 1, 3, 0 };
	int counterClock[4] = { 2, 0, 3, 1 };
	pair<int, int> top = fresher[0];
	pair<int, int> bottom = fresher[1];

	for (int time = 0; time < t; time++) {
		extension();
		circulation(top.first, top.second, counterClock);
		circulation(bottom.first, bottom.second, clock);
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			if (original[row][col] > 0) {
				answer += original[row][col];
			}
		}
	}

	return answer;
}

void extension() {
	vector<vector<int>> extended(n, vector<int>(m, 0));
	queue<pair<int, int>> q;

	// 미세먼지 위치 파악
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			if (original[row][col] > 4) {
				q.push({ row, col });
			}
		}
	}
	
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
			
		int extend = original[now.first][now.second] / 5;

		for (int dir = 0; dir < 4; dir++) {
			int ny = now.first + dy[dir];
			int nx = now.second + dx[dir];

			if (ny > -1 && ny < n && nx > -1 && nx < m) {
				if (original[ny][nx] != -1) {
					extended[ny][nx] += extend;
					original[now.first][now.second] -= extend;
				}
			}
		}
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			original[row][col] += extended[row][col];
		}
	}
}

void circulation(int cy, int cx, int* direction) {
	vector<vector<int>> copied = original;
	int y = cy;
	int x = cx + 1;

	original[y][x] = 0;

	for (int index = 0; index < 4; index++) {
		while (true) {
			int ny = y + dy[direction[index]];
			int nx = x + dx[direction[index]];

			if (!(ny > -1 && ny < n && nx > -1 && nx < m)) {
				break;
			}

			if (cy == ny && cx == nx) {
				break;
			}

			original[ny][nx] = copied[y][x];
			y = ny;
			x = nx;
		}
	}
}