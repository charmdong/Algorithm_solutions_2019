/// ÃÌ¼ö °è»ê
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int n, m;
int relatives[MAX + 1][MAX + 1];
int dist[MAX + 1];
void bfs(int src, int des);

int main()
{
	int src, des, x,y;

	cin >> n >> src >> des;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		relatives[x][y] = relatives[y][x] = 1;
	}

	bfs(src, des);

	cout << ((dist[des] == 0) ? -1 : dist[des]) << endl;

	return 0;
}

void bfs(int src, int des) {
	queue<int> q;

	q.push(src);

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tmp == des) return;

		for (int i = 1; i <= n; i++) {
			if (relatives[tmp][i] && !dist[i]) {
				dist[i] = dist[tmp] + 1;
				q.push(i);
			}
		}
	}
}