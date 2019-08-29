// 저글링 방사능 오염
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int n, m, ans;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0,-1,0,1 };
int board[MAX][MAX];
int visited[MAX][MAX];

bool isInGraph(int x, int y);
int bfs(int y, int x);
int isAlive();

int main()
{
	int x,y,cnt = 0;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &board[i][j]);
	}
	cin >> x >> y;
	cout << bfs(y-1, x-1) + 2 << endl;
	cout << isAlive() << endl;
	return 0;
}

int bfs(int y, int x) {
	vector<vector<pair<int,int>>> list(1, vector<pair<int,int>>());
	list[0].push_back(make_pair(y, x));

	visited[y][x] = 1;
	int cnt = 0;
	while (!list[cnt].empty()) {
		list.push_back(vector<pair<int, int>>());
		for (int i = 0; i < list[cnt].size(); i++) {
			pair<int, int> tmp = list[cnt][i];
			for (int k = 0; k < 4; k++) {
				int nx = tmp.second + dx[k];
				int ny = tmp.first + dy[k];
				if (isInGraph(nx, ny) && !visited[ny][nx] && board[ny][nx]) {
					visited[ny][nx] = 1;
					list[cnt + 1].push_back(make_pair(ny, nx));
				}
			}
		}
		cnt++;
	}

	return cnt;
}

bool isInGraph(int x, int y) {
	if (x >= 0 && x < n)
		if (y >= 0 && y < m)
			return true;
	return false;
}

int isAlive() {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && board[i][j])
				cnt++;
	}
	return cnt;
}