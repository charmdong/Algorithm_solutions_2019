#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;

bool flag;
int N, L, R;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
bool visited[MAX][MAX];
int cntry[MAX][MAX];

bool isInMap(int y, int x);
void bfs(int y, int x);

int main()
{
	int res = 0;
	cin >> N >> L >> R;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cntry[i][j];

	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) 
					bfs(i, j);
			}
		}
		if (flag) {
			res++;
			memset(visited, false, sizeof(visited));
			flag = false;
		}
		else
			break;
	}

	cout << res << endl;

	return 0;
}

void bfs(int y, int x) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		v.push_back(now);

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			int diff = abs(cntry[now.first][now.second] - cntry[ny][nx]);
			
			if (isInMap(ny, nx) && !visited[ny][nx] && diff >= L && diff <= R) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}

	if (v.size() > 1) { // 연합국이  2개 이상인 경우
		flag = true;
		int total = 0;
		for (auto t : v)
			total += cntry[t.first][t.second];
		int after = total / v.size();
		for (int i = 0; i < v.size(); i++)
			cntry[v[i].first][v[i].second] = after;
	}
}

bool isInMap(int y, int x) {
	if (y > -1 && y < N)
		if (x > -1 && x < N)
			return true;
	return false;
}