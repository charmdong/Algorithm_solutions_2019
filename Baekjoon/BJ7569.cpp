#include <iostream>
#include <queue>
#include <vector>
#define MAX 100
using namespace std;

int n, m, h;
int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int board[MAX][MAX][MAX], visited[MAX][MAX][MAX];
queue<vector<int>> q;

void initQueue(); // 처음 시작 가능한 부분을 모두 골라내야함.
bool isInBoard(int z, int y, int x);
bool isAllGood();
int bfs();

int main()
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++)
				cin >> board[i][j][k];
		}
	}
	initQueue();
	cout << bfs() << endl;

	return 0;
}

int bfs() {
	if (isAllGood()) return 0;
	vector<int> now;

	while (!q.empty()) {
		now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = now[2] + dz[i];
			int ny = now[1] + dy[i];
			int nx = now[0] + dx[i];

			if (isInBoard(nz, ny, nx) && board[nz][ny][nx] == 0 && !visited[nz][ny][nx]) {
				board[nz][ny][nx] = visited[nz][ny][nx] = 1;
				board[nz][ny][nx] = board[now[2]][now[1]][now[0]] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}

	return (isAllGood()) ? board[now[2]][now[1]][now[0]]-1 : -1;
}

void initQueue() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 1 && !visited[i][j][k]) {
					for (int r = 0; r < 6; r++) {
						int nz = i + dz[r];
						int ny = j + dy[r];
						int nx = k + dx[r];

						if (board[nz][ny][nx] == 0) {
							visited[i][j][k] = 1;
							q.push({ k, j, i });
							break;
						}
					}
				}
			}
		}
	}
}

bool isInBoard(int z, int y, int x) {
	if (x >= 0 && x < m)
		if (y >= 0 && y < n)
			if (z >= 0 && z < h)
				return true;
	return false;
}

bool isAllGood() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}