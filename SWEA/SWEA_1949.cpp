// 등산로 조정
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, ans;
int map[8][8];
bool visited[8][8];
bool chance;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
vector<pair<int, int>> highest;

void dfs(int y, int x, int len=1);
bool isInMap(int y, int x);

int main()
{
	ios::sync_with_stdio(false);
	
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		cin >> N >> K;
		int max = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[j][k];
				if (max < map[j][k])
					max = map[j][k];
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == max)
					highest.push_back({ j,k });
			}
		}

		for (auto t : highest) {
			chance = true;
			dfs(t.first, t.second);
			visited[t.first][t.second] = false;
		}

		cout << "#" << i << " " << ans << endl;
		ans = 0;
		highest.clear();
	}
 	
	return 0;
}

void dfs(int y, int x, int len) {
	ans = max(ans, len);

	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (isInMap(ny, nx) && !visited[ny][nx]) {
			if (map[ny][nx] < map[y][x]) {// 다음 봉우리가 지금 봉우리보다 낮은 경우
				dfs(ny, nx, len + 1);
				visited[ny][nx] = false;
			}
			else { // 다음 봉우리가 지금 봉우리보다 높거나 같은 경우
				if (chance) { // 깎을 기회가 남은 경우
					if (map[ny][nx] - map[y][x] < K) {
						for (int j = map[ny][nx] - map[y][x] + 1; j <= K; j++) {
							map[ny][nx] -= j;
							chance = false;
							dfs(ny, nx, len + 1);
							chance = true;
							map[ny][nx] += j;
							visited[ny][nx] = false;
						}
					}
				}
			}
		}
	}
}

bool isInMap(int y, int x) {
	if (y > -1 && y < N)
		if (x > -1 && x < N)
			return true;
	return false;
}