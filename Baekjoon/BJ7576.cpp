#include <iostream>
#include <queue>
using namespace std;

int y, x;
bool isInGraph(int a, int b);
int BFS(int **g);

int main()
{
	int **g;
	
	cin >> y >> x;

	g = new int*[x];
	for (int i = 0; i < x; i++)
		g[i] = new int[y];

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			cin >> g[i][j];
	}

	cout << BFS(g) << endl;

	for (int i = 0; i < x; i++)
		delete[] g[i];
	delete[] g;

	return 0;
}

int BFS(int **g) {
	queue<pair<int, int>> q;
	int day = 0;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (g[i][j] == 1)
				q.push(pair<int, int>(i, j));
		}
	}

	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			pair<int, int> tmp = q.front();
			if (isInGraph(tmp.first - 1, tmp.second) && g[tmp.first - 1][tmp.second] == 0) {
				g[tmp.first - 1][tmp.second] = 1;
				q.push(pair<int, int>(tmp.first - 1, tmp.second));
			}
			if (isInGraph(tmp.first + 1, tmp.second) && g[tmp.first + 1][tmp.second] == 0) {
				g[tmp.first + 1][tmp.second] = 1;
				q.push(pair<int, int>(tmp.first + 1, tmp.second));
			}
			if (isInGraph(tmp.first, tmp.second-1) && g[tmp.first][tmp.second-1] == 0) {
				g[tmp.first][tmp.second-1] = 1;
				q.push(pair<int, int>(tmp.first, tmp.second-1));
			}
			if (isInGraph(tmp.first, tmp.second + 1) && g[tmp.first][tmp.second + 1] == 0) {
				g[tmp.first][tmp.second + 1] = 1;
				q.push(pair<int, int>(tmp.first, tmp.second + 1));
			}
			q.pop();
		}
		day++;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			if (g[i][j] == 0)
				return -1;
	}
	return day-1;
}

bool isInGraph(int a, int b) {
	if (a >= 0 && a < x)
		if (b >= 0 && b < y)
			return true;
	return false;
}