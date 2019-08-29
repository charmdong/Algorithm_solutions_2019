#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int n, low,high, cnt, maxCnt;
int h[MAX][MAX];
int visited[MAX][MAX];
vector<int> res;

bool isInGraph(int x, int y);
void DFS(int x, int y, int  height);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
			low = min(low, h[i][j]);
			high = max(high, h[i][j]);
		}
	}

	for (int i = low; i <= high; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (visited[j][k] == 0 && h[j][k] > i) { 
					DFS(j, k, i);
					cnt++;
				}
			}
		}
		maxCnt = max(maxCnt, cnt);
		cnt = 0;
		// initing visited Array
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = 0;
	}

	cout << maxCnt << endl;

	return 0;
}

void DFS(int x, int y, int height) { // using g and visited Arrays
	visited[x][y] = 1;

	if (isInGraph(x - 1, y) && !visited[x - 1][y] && h[x - 1][y] > height)
		DFS(x - 1, y, height);
	if (isInGraph(x + 1, y) && !visited[x + 1][y] && h[x + 1][y] > height)
		DFS(x + 1, y, height);
	if (isInGraph(x, y-1) && !visited[x][y-1] && h[x][y-1] > height)
		DFS(x, y - 1, height);
	if (isInGraph(x, y + 1) && !visited[x][y + 1] && h[x][y + 1] > height)
		DFS(x, y + 1, height);
}

bool isInGraph(int x, int y) {
	if (x >= 0 && x < n) {
		if (y >= 0 && y < n)
			return true;
	}
	return false;
}