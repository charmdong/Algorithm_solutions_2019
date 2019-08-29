// 중량제한
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ans, n,m;
int src, des, limit;
int f1, f2;
bool check;
vector<vector<pair<int, int>>> map; // first = des, second = limit
vector<bool> visited;

void dfs(int start, int limit=1000000001);
int bfs(int src=f1, int des=f2);

int main()
{
	cin >> n >> m;
	map.assign(n + 1, vector<pair<int, int>>());
	visited.assign(n+1, false);

	for (int i = 0; i < m; i++) {
		cin >> src >> des >> limit;
		map[src].push_back({ des,limit });
		map[des].push_back({ src,limit });
	}
	
	/*for (int i = 1; i <= n; i++) {
		if(map[i].size() != 0)
			sort(map[i].begin(), map[i].end());
	}*/

	/*for (int i = 0; i < map[f1].size(); i++)
		if (map[f1][i].first == f2)
			check = true;
	*/
	cin >> f1 >> f2;
	dfs(f1);
	cout << ans << endl;
	
	return 0;
}

int bfs(int src, int des) {
	queue<pair<int, int>> q;
	q.push({ des, 0 });
	visited[src] = true; 
	return 0;
}

void dfs(int src, int limit) {
	visited[src] = true;

	if (src == f2) {
		ans = check ? max(ans, limit) : min(ans, limit); // 수정 필요
		return;
	}

	for (int i = 0; i < map[src].size(); i++) {
		int next = map[src][i].first; // 다음 섬
		if (!visited[next]) {
			dfs(next, min(limit, map[src][i].second));
			visited[next] = false;
		}
	}
}