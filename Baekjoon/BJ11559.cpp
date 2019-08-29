#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define COL 12
#define ROW 6
using namespace std;

int ans;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
char map[COL][ROW];
bool visited[COL][ROW];
vector<pair<int, int>> puyo;

void searchDfs(int y, int x, char ch);
void searchBfs(int y, int x, char ch);
void paint();
bool isInMap(int y, int x);

void print() {
	cout << endl;
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++)
			cout << map[i][j];
		cout << endl;
	}
}

int main()
{
	for (int i = 0; i < COL; i++)
		for (int j = 0; j < ROW; j++)
			cin >> map[i][j];

	while (1) {
		bool check = false;

		for (int i = 0; i < COL; i++) {
			for (int j = 0; j < ROW; j++) {
				if (!visited[i][j] && map[i][j] != '.') {
					puyo.clear();
					//puyo.push_back(make_pair(i, j));
					//searchDfs(i,j,map[i][j]);
					searchBfs(i, j, map[i][j]);
					if (puyo.size() >= 4) {
						check = true;
						for (auto t : puyo)
							map[t.first][t.second] = '.';
					}
				}
			}
		}
		
		if (!check) break;
		else ans++;
		paint();
		memset(visited, false, sizeof(visited));
	}
	
	cout << ans << endl;

	return 0;
}

void searchDfs(int y, int x, char ch) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isInMap(ny, nx) && !visited[ny][nx] && map[ny][nx] == ch) {
			puyo.push_back(make_pair(ny, nx));
			searchDfs(ny, nx, ch);
		}
	}
}

void searchBfs(int y, int x, char ch) {
	queue < pair<int, int>> q;

	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		puyo.push_back({ now.first, now.second });

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (isInMap(ny, nx) && !visited[ny][nx] && map[ny][nx] == ch) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

void paint() {
	for (int i = 0; i < ROW; i++) {
		for (int j = COL - 2; j >= 0; j--) {
			for (int k = COL - 1; k > j; k--) {
				if (map[j][i] != '.' && map[k][i] == '.') {
					map[k][i] = map[j][i];
					map[j][i] = '.';
					break;
				}
			}
		}
	}
}

bool isInMap(int y, int x) {
	if (y > -1 && y < COL)
		if (x > -1 && x < ROW)
			return true;
	return false;
}