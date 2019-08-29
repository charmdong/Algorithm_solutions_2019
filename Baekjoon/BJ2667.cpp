#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;

bool isInGraph(int a, int b);
void BFS();
void DFS(int x, int y);

vector<pair<int, int>> cmp = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
vector<int> v;
int total;
int n;
int **t;
int visited[MAX][MAX];

int main()
{
	cin >> n;

	t = new int*[n];
	for (int i = 0; i < n; i++)
		t[i] = new int[n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &t[i][j]);
	}

	//BFS();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			DFS(i, j);
			if( total != 0)
				v.push_back(total);
			total = 0;
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto res : v)
		cout << res << endl;

	for (int i = 0; i < n; i++)
		delete[] t[i];
	delete[] t;

	return 0;
}

void BFS() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (t[i][j] == 1 && visited[i][j] == 0) {
				int cnt = 1;

				visited[i][j] = 1;

				q.push(pair<int, int>(i, j));
				while (!q.empty()) {
					pair<int, int> tmp = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						if (isInGraph(tmp.first + cmp[k].first, tmp.second + cmp[k].second)
							&& t[tmp.first + cmp[k].first][tmp.second + cmp[k].second] == 1
							&& visited[tmp.first + cmp[k].first][tmp.second + cmp[k].second] == 0) {
							visited[tmp.first + cmp[k].first][tmp.second + cmp[k].second] = 1;
							q.push(pair<int, int>(tmp.first + cmp[k].first, tmp.second + cmp[k].second));
							cnt++;
						}
					}
				}
				v.push_back(cnt);
			}
		}
	}

}

void DFS(int x, int y) {
	if (isInGraph(x, y)) {
		if (t[x][y] == 1 && visited[x][y] == 0) {
			visited[x][y] = 1;
			total++;
			DFS(x - 1, y);
			DFS(x + 1, y);
			DFS(x, y - 1);
			DFS(x, y + 1);
		}
	}
}

bool isInGraph(int a, int b) {
	if (a >= 0 && a < n)
		if (b >= 0 && b < n)
			return true;
	return false;
}