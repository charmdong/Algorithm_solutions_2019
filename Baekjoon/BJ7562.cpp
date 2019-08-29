#include <iostream>
#include <queue>
#define MAX 300
using namespace std;

int dx[8] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[8] = { -2, 2, -1,1, -2,2,-1,1 };
int board[MAX][MAX];
int dist[MAX][MAX];
int n;
int bfs(pair<int, int> src, pair<int, int> des);
bool isInGraph(int x, int y);

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> n;
		pair<int, int > src, des;
		cin >> src.first >> src.second >> des.first >> des.second;
		cout << bfs(src, des) << endl;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				board[j][k] = dist[j][k] = 0;
		}
	}

	return 0;
}

int bfs(pair<int, int> src, pair<int, int> des) {
	if (src == des) return 0;
	queue<pair<int, int>> q;

	q.push(src);

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = tmp.first + dy[i];
			int nx = tmp.second + dx[i];
			if (isInGraph(nx, ny) && !dist[ny][nx]) {
				dist[ny][nx] = dist[tmp.first][tmp.second] + 1;
				if (make_pair(ny, nx) == des) return dist[des.first][des.second];
				q.push(make_pair(ny, nx));
			}
		}
	}

	return dist[des.first][des.second];
}

bool isInGraph(int x, int y) {
	if (x >= 0 && x < n)
		if (y >= 0 && y < n)
			return true;
	return false;
}