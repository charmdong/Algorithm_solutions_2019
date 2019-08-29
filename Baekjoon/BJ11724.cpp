#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 1000
using namespace std;

int n, m, cnt;
int visited[N + 1];
int g[N+1][N+1];

bool isAllVisited(int *);
void DFS(int s);
void BFS(int s);

int main()
{
	int u, v;
	cin >> n >> m;

	for (int i = 0; i < m; i++) { // building graph
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0 && !isAllVisited(visited))
			cnt++;
		BFS(i);
	}
	
	cout << cnt << endl;

	return 0;
}

bool isAllVisited(int *visited) {
	for (int i = 1; i <= n; i++)
		if (visited[i] == 0)
			return false;
	return true;
}

void DFS(int s) {
	visited[s] = 1;
	for (int i = 1; i <= n; i++) {
		if (g[s][i] == 1 && visited[i] == 0){ // connected & not visited
			DFS(i);
		}
	}
}

void BFS(int s) {
	queue<int> q;

	visited[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (g[tmp][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}