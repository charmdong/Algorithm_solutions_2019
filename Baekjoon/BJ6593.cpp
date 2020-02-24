/**
 * @author : donggun.chung
 * @date : 2020.02.22
 * @site : BOJ
 * @prob_Info : 6593 상범 빌딩 
 * @time : 0ms
 * @memory : 2168KB
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int L, R, C;
char building[30][30][30];
bool visited[30][30][30];

int dl[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { -1, 0, 1, 0, 0, 0 };
int dx[6] = { 0, 1, 0, -1, 0, 0 };

struct Floor {
	int layer;
	int row;
	int col;
	int time;

	Floor(int l, int r, int c, int t) : layer(l), row(r), col(c), time(t) {}
};

void solution(int sl, int sy, int sx);
void init();
bool isInBuilding(int l, int y, int x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sl, sy, sx;

	while (true) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) {
			break;
		}

		for (int layer = 0; layer < L; layer++) {
			for (int row = 0; row < R; row++) {
				for (int col = 0; col < C; col++) {
					cin >> building[layer][row][col];

					if (building[layer][row][col] == 'S') {
						sl = layer;
						sy = row;
						sx = col;
					}
				}
			}
		}

		solution(sl, sy, sx);

		init();
	}

	return 0;
}

void solution(int sl, int sy, int sx) {
	queue<Floor> q;

	visited[sl][sy][sx] = true;
	q.push(Floor(sl, sy, sx, 0));

	while (!q.empty()) {
		Floor current = q.front();
		int curLayer = current.layer;
		int curRow = current.row;
		int curCol = current.col;
		int curTime = current.time;
		q.pop();

		if (building[curLayer][curRow][curCol] == 'E') {
			cout << "Escaped in " << curTime << " minute(s).\n";
			return;
		}

		for (int dir = 0; dir < 6; dir++) {
			int nl = curLayer + dl[dir];
			int ny = curRow + dy[dir];
			int nx = curCol + dx[dir];

			if (isInBuilding(nl, ny, nx) && building[nl][ny][nx] != '#' && !visited[nl][ny][nx]) {
				visited[nl][ny][nx] = true;
				q.push(Floor(nl, ny, nx, curTime + 1));
			}
		}
	}

	cout << "Trapped!\n";
}

void init() {
	for (int layer = 0; layer < L; layer++) {
		for (int row = 0; row < R; row++) {
			fill(visited[layer][row], visited[layer][row] + C, false);
		}
	}
}

bool isInBuilding(int l, int y, int x) {
	return ((l > -1 && l < L) && (y > -1 && y < R) && (x > -1 && x < C));
}