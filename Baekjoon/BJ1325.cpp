#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10000
using namespace std;

int n, m;
vector<bool> visited;
vector<int> board[MAX + 1];
vector<int> res;

void dfs(int now);
int bfs(int now);

int main()
{
	cin >> n >> m;
	
	int src, des;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &src, &des);
		board[des].push_back(src);
	}

	res.assign(n + 1, 0);
	for (int i = 0; i < n; i++) {
		visited.assign(n + 1, false);
		/*dfs(i + 1);
		res[i+1] = count(visited.begin(),visited.end(), true);*/
		res[i + 1] = bfs(i + 1);
	}

	int maxVal = *max_element(res.begin(), res.end());
	for (int i = 1; i <= n; i++)
		if (res[i] == maxVal)
			cout << i << " ";
	cout << "\n";

	return 0;
}

void dfs(int now) {
	visited[now] = true;
	
	int num = board[now].size();
	for (int i = 0; i < num; i++) {
		int next = board[now][i];
		if (!visited[next])
			dfs(next);
	}
}

int bfs(int now) {
	queue<int> q;
	int cnt = 1;

	visited[now] = true;
	q.push(now);

	while (!q.empty()) {
		int present = q.front();
		q.pop();

		int num = board[present].size();

		for (int i = 0; i < num; i++) {
			int next = board[present][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}

	return cnt;
}