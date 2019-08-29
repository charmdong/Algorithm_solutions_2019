#include <iostream>
#include <vector>
#include <algorithm>
#define USER 100
using namespace std;

int n, m;
int users[USER + 1][USER + 1];
int visited[USER + 1];

int bfs(int src, int des);

int main()
{
	vector<pair<int,int>> res;
	int src, des, total = 0;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> src >> des;
		users[src][des] = users[des][src] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			total += bfs(i, j);
			for (int k = 1; k <= n; k++)
				visited[k] = 0;
		}
		res.push_back(make_pair(total, i));
		total = 0;
	}

	sort(res.begin(), res.end());
	cout << res.front().second << "\n";

	return 0;
}

int bfs(int src, int des) {
	vector<vector<int>> list(1, vector<int>());

	list[0].push_back(src);
	visited[src] = 1;
	int cnt = 0;

	while (!list[cnt].empty()) {
		list.push_back(vector<int>());
		for (int i = 0; i < list[cnt].size(); i++) {
			int now = list[cnt][i];
			if (now == des) {
				return cnt;
			}
			for (int j = 1; j <= n; j++) {
				if (users[now][j] && !visited[j]) {
					visited[j] = 1;
					list[cnt + 1].push_back(j);
				}
			}
		}
		cnt++;
	}
}