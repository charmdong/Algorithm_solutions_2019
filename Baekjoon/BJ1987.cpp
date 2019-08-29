#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int x, y, cnt=0, ans = 1;
int g[MAX][MAX];
vector<int> visited(26, 0);
bool isInGraph(int a, int b);
void DFS(int sx, int sy);

int main()
{
	char ch;
	cin >> x >> y;

	for (int i = 0; i < x; i++) { // build graph
		for (int j = 0; j < y; j++) {
			cin >> ch;
			g[i][j] = ch - 65;
		}
	}

	DFS(0, 0);
	cout << ans << endl;
	return 0;
}

void DFS(int sx, int sy) {
	ans = max(++cnt, ans);
	visited[g[sx][sy]] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];

		if (isInGraph(nx, ny) && visited[g[nx][ny]] == 0)
			DFS(nx, ny);
	}

	cnt--;
	visited[g[sx][sy]] = 0;
}

bool isInGraph(int a, int b) {
	if (a >= 0 && a < x)
		if (b >= 0 && b < y)
			return true;
	return false;
}