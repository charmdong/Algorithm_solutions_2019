#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> map;
vector<bool> visited;

void bfs(int start);

int main()
{
	int test;

	cin >> test;
	for (int i = 0; i < test; i++) {
		int ans = 0;
		cin >> n;
		map.assign(n+1,0);
		visited.assign(n + 1, false);

		for (int j = 0; j < n; j++)
			cin >> map[j + 1];

		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				bfs(j);
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

void bfs(int start) {
	queue<int> q;
	q.push(start);

	visited[start] = true;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		int next = map[now];
		if (!visited[next]) {
			visited[next] = true;
			q.push(next);
		}
	}
}