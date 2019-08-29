#include <iostream>
#include <queue>
#include <vector>
#define MAX 20000
#define BLK 'B'
#define WHT 'W'
using namespace std;

int testCase, vertex, edge;
vector<vector<int>> graph;
vector<bool> visited;
vector<char> color;

bool bfs(int src);
bool dfs(int src, char color);

int main()
{
	int src, des;
	bool check = false;
	
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> vertex >> edge;
		
		graph.assign(vertex + 1, vector<int>());
		visited.assign(vertex + 1, false);
		color.assign(vertex + 1, '\0');

		for (int j = 0; j < edge; j++) { // set graph
			cin >> src >> des;
			graph[src].push_back(des);
			graph[des].push_back(src);
		}
		// 모든 정점에 대해서 수행해야한다.
		for (int j = 1; j <= vertex; j++) {
			if (!visited[j]) {
				/*if (!bfs(j)) {
					check = true;
					break;
				}*/
				if (!dfs(j, BLK)) {
					check = true;
					break;
				}
			}
		}

		if (check)
			cout << "NO\n";
		else
			cout << "YES\n";
		check = false;
	}
	return 0;
}

bool bfs(int src) {
	queue<int> q;

	q.push(src);
	visited[src] = true;
	color[src] = BLK;

	while (!q.empty()) {
		int now = q.front();
		char nowColor = color[now];
		q.pop();

		for (int next : graph[now]) { // t : now정점과 인접한 정점들의 번호
			if (color[next] == nowColor) return false;
			if (!visited[next]) {
				visited[next] = true;
				color[next] = (nowColor == BLK) ? WHT : BLK;
				q.push(next);
			}
		}
	}
	return true;
}

bool dfs(int src, char c) {
	visited[src] = true;
	color[src] = c;

	for (int next : graph[src]) { // next : src정점과 인접한 정점들의 번호
		if (color[next] == c) return false;
		if (!visited[next] && !dfs(next, (c == BLK) ? WHT : BLK)) // Check Point
			return false;
	}
	return true;
}