#include <iostream>
#include <queue>
#include <vector>
#define MAX 50
using namespace std;

bool isInGraph(int a, int b);
void BFS();
int DFS(int, int);

vector<pair<int, int>> cmp = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int visited[MAX][MAX];
int x, y;
int t[MAX][MAX];
int cnt;

int main()
{
	int testCase, loc, a,b;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cnt = 0;
		cin >> y >> x >> loc;
		
		for (int j = 0; j <MAX; j++) { // 초기화
			for (int k = 0; k <MAX; k++)
				t[j][k] = visited[j][k] = 0;
		}

		for (int j = 0; j < loc; j++) { // 배추 위치 입력
			cin >> a >> b;
			t[b][a] = 1;
		}

		//BFS();

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (DFS(i, j) == 1)
					cnt++;
			}
		}
		cout << cnt  << endl;
	}
	return 0;
}

void BFS() {
	queue<pair<int, int>> q;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (t[i][j] == 1 && visited[i][j] == 0) {
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
						}
					}
				}
				cnt++;
			}
		}
	}
}


int DFS(int a, int b) {
	if (isInGraph(a, b)) {
		if(t[a][b] == 1 && visited[a][b] == 0){
			visited[a][b] = 1;
			DFS(a - 1, b);
			DFS(a + 1, b);
			DFS(a, b - 1);
			DFS(a, b + 1);
			return 1;
		}
	}
	return 0;
}

bool isInGraph(int a, int b) {
	if (a >= 0 && a < x)
		if (b >= 0 && b < y)
			return true;
	return false;
}