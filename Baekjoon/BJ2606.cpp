#include <iostream>
#include <queue>
using namespace std;

int n, connect;
vector<vector<int>> map;
vector<bool> visited;

int bfs(int start=1);

int main()
{
	cin >> n;
	map.assign(n + 1, vector<int>(n + 1, 0));
	visited.assign(n + 1, false);

	cin >> connect;
	for (int i = 0; i < connect; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	cout << bfs() << endl;

	return 0;
}

int bfs(int start) {
	queue<int> q;
	int ans =-1;
	q.push(start);

	visited[start] = true;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		ans++;
		for (int next = 1; next <= n; next++) {
			if (!visited[next] && map[now][next] == 1) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return ans;
}