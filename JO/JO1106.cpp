#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int dx[8] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[8] = { -2, 2, -1,1, -2,2,-1,1 };
int g[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];
int n, m, cnt;
int BFS(pair<int,int> src,pair<int, int> des);
bool isInGraph(int x, int y);

int main()
{
	cin >> n >> m;
	pair<int, int > src, des;
	cin >> src.first >> src.second >> des.first >> des.second;
	cout << BFS(src, des) << endl;
	return 0;
}

int BFS(pair<int, int> src, pair<int, int> des) {
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
	if (x >= 1 && x <= m)
		if (y >= 1 && y <= n)
			return true;
	return false;
}