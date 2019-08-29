// You should think about the cases such as CRASHED / NON-CRASHED.
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1000
using namespace std;

class node {
public:	
	int y, x,crashed;
	node(int col, int row, int c) : y(col), x(row), crashed(c) {}
};

int col, row;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
int map[MAX + 1][MAX + 1];
int dist[2][MAX + 1][MAX + 1];

int bfs(int y = 1, int x = 1, int c = 0);
bool isInBoard(int y, int x);

int main()
{
	cin >> col >> row;
	
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			scanf("%1d", &map[i + 1][j + 1]);
	
	cout << bfs() << endl;

	return 0;
}

int bfs(int y, int x, int c) {
	queue<node> q;

	dist[c][y][x] = 1;
	q.push(node(y,x, c));

	while (!q.empty()) {
		node now = q.front(); q.pop();

		if (now.y == col && now.x == row) // µµÂø
			return dist[now.crashed][col][row];

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (isInBoard(ny, nx)) {
				if (map[ny][nx] == 0) {
					if (!dist[now.crashed][ny][nx]) {// non visited
						dist[now.crashed][ny][nx] = dist[now.crashed][now.y][now.x] + 1;
						q.push(node(ny, nx, now.crashed));
					}
				}
				else {
					if (!now.crashed) {
						dist[now.crashed + 1][ny][nx] = dist[now.crashed][now.y][now.x] + 1;
						q.push(node(ny, nx, now.crashed + 1));
					}
				}
			}
		}
	}

	return -1;
}

bool isInBoard(int y, int x) {
	if (y > 0 && y <= col)
		if (x > 0 && x <= row)
			return true;
	return false;
}