#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 11
using namespace std;

int test, m, n;
vector<int> a, b;
int dy[5] = { 0, -1,0,1,0 };
int dx[5] = { 0, 0,1,0,-1 };
bool visited[MAX][MAX];
int map[8][MAX][MAX];
int power[8];
int dist[MAX][MAX];

void extendBFS(int y, int x, int r, int index);
int solution();
bool isInMap(int y, int x);

int main()
{
	cin >> test;
	
	for (int i = 1; i <= test; i++) {
		cin >> m >> n;
		
		a.assign(m+1, 0);
		b.assign(m+1, 0);
		for (int j = 1; j <= m; j++)
			cin >> a[j];
		for (int j = 1; j <= m; j++)
			cin >> b[j];
		
		int y, x, r;
		for (int j = 0; j < n; j++) {
			cin >> x >> y >> r >> power[j];
			extendBFS(y, x, r, j);
			memset(dist, 0, sizeof(dist));
			memset(visited, false, sizeof(visited));
		}

		cout << "#" << i << " " << solution() << endl;;
		memset(map, 0, sizeof(map));
	}

	return 0;
}

bool isInMap(int y, int x) {
	if (y > 0 && y < MAX)
		if (x > 0 && x < MAX)
			return true;
	return false;
}

void extendBFS(int y, int x, int r, int index) { // 각 BC에 대한 확장 정보 저장
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	map[index][y][x] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();

		if (dist[now.first][now.second] == r)
			return;

		for (int i = 1; i <= 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (isInMap(ny, nx) && !visited[ny][nx]) {
				visited[ny][nx] = true;
				dist[ny][nx] = dist[now.first][now.second] + 1;
				map[index][ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}

int solution() {
	int ans = 0;

	pair<int, int> sa(1, 1), sb(10, 10);

	for (int i = 0; i <= m; i++) {
		sa = { sa.first + dy[a[i]], sa.second + dx[a[i]] }; // 다음 사용자 a의 위치
		sb = { sb.first + dy[b[i]], sb.second + dx[b[i]] }; // 다음 사용자 b의 위치
		
		int res = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int p = 0;
				if (j == k) { // 같은 배터리인 경우
					if (map[j][sa.first][sa.second] || map[k][sb.first][sb.second])
						p = power[j];
				}
				else {
					if (map[j][sa.first][sa.second])
						p += power[j];
					if (map[k][sb.first][sb.second])
						p += power[k];
				}
				res = max(res, p);
			}
		}
		ans += res;
	}

	return ans;
}