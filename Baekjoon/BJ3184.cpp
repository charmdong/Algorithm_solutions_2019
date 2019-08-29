//¾ç
#include <iostream>
#include <queue>
#define MAX 250
using namespace std;

int n,m, wolf, sheep;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
bool visited[MAX][MAX];
char map[MAX][MAX];
void bfs(int y = 0, int x = 0);
bool isInMap(int y, int x);

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'v')
				wolf++;
			else if (map[i][j] == 'o')
				sheep++;
			else continue;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j]!='#')
				bfs(i, j);
		}
	}

	cout << sheep << " " << wolf << endl;

	return 0;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	int w=0, s=0;

	q.push({ y,x });
	visited[y][x] = true;

	if (map[y][x] == 'v')
		w++;
	else if (map[y][x] == 'o')
		s++;

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (isInMap(ny, nx) && !visited[ny][nx] && map[ny][nx] != '#') {
				visited[ny][nx] = true;
				if (map[ny][nx] == 'v')
					w++;
				if (map[ny][nx] == 'o')
					s++;
				q.push({ ny,nx });
			}
		}
	}
	
	if (s > w)
		wolf -= w;
	else
		sheep -= s;
}

bool isInMap(int y, int x) {
	if (y > -1 && y < n)
		if (x > -1 && x < m)
			return true;
	return false;
}