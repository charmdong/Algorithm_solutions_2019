#include <iostream>
#include <cstring>
#include <queue>
#define MAX 300
using namespace std;

int n, m;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int board[MAX][MAX];
bool visited[MAX][MAX];

bool isInBoard(int y, int x);
int bfs();

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	int year = 0;

	while (1) {
		int island = bfs();
		if (island == 0) {
			year = 0;
			break;
		}
		if (island > 1)
			break;
		year++;
		memset(visited, false, sizeof(visited));
	}

	cout << year << endl;

	return 0;
}

int bfs() { // 빙산 높이 줄이고, 섬의 개수 반환 - 다 녹았으면 0 반환
	int cnt = 0; // 섬의 개수 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0 && !visited[i][j]) {
				cnt++;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visited[i][j] = true;

				while (!q.empty()) {
					pair<int, int> now = q.front(); q.pop();

					for (int k = 0; k < 4; k++) { // 4방향에 대해 주변 바닷가 탐색
						int ny = now.first + dy[k];
						int nx = now.second + dx[k];

						if (isInBoard(ny, nx) && board[ny][nx] == 0 && !visited[ny][nx]) {
							if (board[now.first][now.second] > 0)
								board[now.first][now.second]--;
						}
					}

					for (int k = 0; k < 4; k++) {
						int ny = now.first + dy[k];
						int nx = now.second + dx[k];

						if (isInBoard(ny, nx) && board[ny][nx] != 0 && !visited[ny][nx]) {
							visited[ny][nx] = true;
							q.push(make_pair(ny, nx));
						}
					}
				}
			}
		}
	}

	return cnt;
}

bool isInBoard(int y, int x) {
	if (y > -1 && y < n)
		if (x > -1 && x < m)
			return true;
	return false;
}