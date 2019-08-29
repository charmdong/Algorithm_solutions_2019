#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;

int g[MAX][MAX];
int visited[MAX][MAX];
int x, y, square, num;
vector<pair<int, int>> cmp = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
vector<int> res;
void DFS(int x, int y);
void BFS();
bool isInGraph(int a, int b);

int main()
{
	pair<int, int> src, des;
	cin >> x >> y >> square;
	
	for (int i = 0; i < square; i++) {
		cin >> src.second >> src.first >> des.second >> des.first;
		
		for (int j = x - des.first; j < x - src.first; j++) {
			for (int k = src.second; k < des.second; k++)
				g[j][k] = 1;
		}
	}
	BFS();
	/*for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			DFS(i, j);
			if (num != 0) {
				res.push_back(num);
				num = 0;
			}
		}
	}*/

	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int t : res)
		cout << t << " ";
	cout << endl;

	return 0;
}

void DFS(int x, int y) {
	if (isInGraph(x,y) && g[x][y] == 0 && visited[x][y] == 0) {
		visited[x][y] = 1;
		num++;
		DFS(x - 1, y);
		DFS(x + 1, y);
		DFS(x, y - 1);
		DFS(x, y + 1);
	}
}

void BFS() {
	queue<pair<int ,int>> q;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (g[i][j] == 0 && visited[i][j] == 0) {
				num = 1;
				visited[i][j] = 1;

				q.push(make_pair(i, j));
				while (!q.empty()) {
					pair<int, int> tmp = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						if (isInGraph(tmp.first + cmp[k].first, tmp.second + cmp[k].second)
							&& g[tmp.first + cmp[k].first][tmp.second + cmp[k].second] == 0
							&& visited[tmp.first + cmp[k].first][tmp.second + cmp[k].second] == 0) {
							visited[tmp.first + cmp[k].first][tmp.second + cmp[k].second] = 1;
							q.push(pair<int, int>(tmp.first + cmp[k].first, tmp.second + cmp[k].second));
							num++;
						}
					}
				}
				res.push_back(num);
			}
		}
	}
}

bool isInGraph(int a, int b) {
	if (a >= 0 && a < x)
		if (b >= 0 && b < y)
			return true;
	return false;
}