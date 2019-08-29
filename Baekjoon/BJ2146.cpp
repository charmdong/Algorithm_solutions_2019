#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int n;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
int map[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX];
vector<int> res;

void numberingBfs();
void bridgeBfs();
bool isInMap(int y, int x);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	numberingBfs();
	bridgeBfs();

	cout << *min_element(res.begin(), res.end()) << endl;
	
	return 0;
}

void bridgeBfs() { // TO DO : 간척 사업 진행하면서 그 길이를 저장, 서로 다른 섬이 만나는 지 체크, 만나는 지점 모두 res에 저장
	queue<pair<int, int>> q;
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (map[i][j] != 0)
				q.push(make_pair(i, j));
	
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (isInMap(ny, nx)) {
				if (map[ny][nx] != 0 && map[ny][nx] != map[now.first][now.second]) {
					res.push_back(dist[ny][nx] + dist[now.first][now.second]);
					continue;
				}
				
				if (map[ny][nx] == 0) { // Extend bridge
					map[ny][nx] = map[now.first][now.second];
					dist[ny][nx] = dist[now.first][now.second] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

void numberingBfs() {
	int index = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				index++;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visited[i][j] = true;
				map[i][j] = index;

				while (!q.empty()) {
					pair<int, int> now = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = now.first + dy[k];
						int nx = now.second + dx[k];

						if (isInMap(ny, nx) && !visited[ny][nx] && map[ny][nx] == 1) {
							visited[ny][nx] = true;
							map[ny][nx] = index;
							q.push(make_pair(ny, nx));
						}
					}
				}
			}
		}
	}
}

bool isInMap(int y, int x) {
	if (y > -1 && y < n)
		if (x > -1 && x < n)
			return true;
	return false;
}