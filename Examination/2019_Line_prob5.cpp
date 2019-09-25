#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row, col;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
vector<vector<bool>> visited;
vector<vector<int>> board;
vector<vector<int>> timeList;
vector<vector<int>> dp;

void solution(int y, int x);
bool isInBoard(int y, int x);

int main()
{
	int desY, desX;
	cin >> col >> row;
	cin >> desX >> desY;

	visited.assign(row + 1, vector<bool>(col + 1, false));
	timeList.assign(row + 1, vector<int>(col + 1, 0));
	dp.assign(row + 1, vector<int>(col + 1, 0));

	solution(desY, desX);

	return 0;
}

void solution(int desY, int desX) {
	int answer = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	if (!isInBoard(desY, desX)) {
		cout << "fail" << endl;
		return;
	}

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (now.first == desY && now.second == desX) {
			answer = timeList[now.first][now.second];
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			int ny = now.first + dy[dir];
			int nx = now.second + dx[dir];

			if (isInBoard(ny, nx)) {
				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny, nx });
					timeList[ny][nx] = timeList[now.first][now.second] + 1;
				}
			}
		}
	}

	for (int i = 1; i <= row; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= col; i++) {
		dp[i][0] = 1;
	}

	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= col; c++) {
			dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
		}
	}

	cout << answer << endl;
	cout << dp[desY][desX] << endl;
}

bool isInBoard(int y, int x) {
	if (y > -1 && y <= row) {
		if (x > -1 && x <= col) {
			return true;
		}
		return false;
	}
	return false;
}