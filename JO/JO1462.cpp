// º¸¹°¼¶
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50
using namespace std;

int n, m, ans;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int board[MAX][MAX];
bool visited[MAX][MAX];

bool isInGraph(int x, int y);
int bfs(int y, int x);

int main()
{
	char ch;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			board[i][j] = (ch == 'L') ? 1 : 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans << endl;
	return 0;
}

int bfs(int y, int x) {
	vector<vector<pair<int, int>>> list(1, vector<pair<int, int>>());
	list[0].push_back(make_pair(y, x));
	visited[y][x] = true;
	int cnt = 0;
	
	while (!list[cnt].empty()) {
		list.push_back(vector<pair<int, int>>());
		
		for (int i = 0; i < list[cnt].size(); i++) {
			pair<int, int> tmp = list[cnt][i];
			
			for (int k = 0; k < 4; k++) {
				int nx = tmp.second + dx[k];
				int ny = tmp.first + dy[k];
				
				if (isInGraph(nx, ny) && !visited[ny][nx] && board[ny][nx]) {
					visited[ny][nx] = true;
					list[cnt + 1].push_back(make_pair(ny, nx));
				}
			}
		}
		cnt++;
	}

	if (list[cnt].size() == 0)
		list.pop_back();

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			visited[i][j] = false;

	return list.size()-1;
}

bool isInGraph(int x, int y) {
	if (x >= 0 && x < m)
		if (y >= 0 && y < n)
			return true;
	return false;
}