#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int r, c;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char map[MAX][MAX];
int water[MAX][MAX];
int hed[MAX][MAX];
queue<pair<int, int>> waterQueue, hedQueue;

bool isInBoard(int y, int x);

int dfs();

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			water[i][j] = hed[i][j] = -1;
			if (map[i][j] == '*') {
				waterQueue.push(make_pair(i, j));
				water[i][j] = 0;
			}
			if (map[i][j] == 'S') {
				hedQueue.push(make_pair(i, j));
				hed[i][j] = 0;
			}
		}
	}

	int ans = dfs();
	ans != 0 ? cout << ans << endl : cout << "KAKTUS\n";

	return 0;
}

int dfs() {
	int depth = 1;
	int hedSize = hedQueue.size();
	int waterSize = waterQueue.size();
	
	while (hedSize) {
		while (waterSize--) { // Extending water positions
			pair<int, int> nowWater = waterQueue.front(); waterQueue.pop();

			for (int i = 0; i < 4; i++) {
				int ny = nowWater.first + dy[i];
				int nx = nowWater.second + dx[i];

				if (isInBoard(ny, nx) && water[ny][nx] == -1) {
					if (map[ny][nx] != 'X' && map[ny][nx] != 'D') {
						water[ny][nx] = depth;
						waterQueue.push(make_pair(ny, nx));
					}
				}
			}
		}
		
		while (hedSize) { // Move to possible position
			hedSize--;
			pair<int, int> nowHed = hedQueue.front(); hedQueue.pop();

			for (int i = 0; i < 4; i++) {
				int ny = nowHed.first + dy[i];
				int nx = nowHed.second + dx[i];

				if (map[ny][nx] == 'D')
					return depth;

				if (isInBoard(ny, nx) && hed[ny][nx] == -1) {
					if (map[ny][nx] != 'X' && water[ny][nx] < 0) {
						hed[ny][nx] = depth;
						hedQueue.push(make_pair(ny, nx));
					}
				}
			}
			
		}
		
		if (hedSize == 0) {
			hedSize = hedQueue.size();
			waterSize = waterQueue.size();
			depth++;
		}
	}
	return 0;
}

bool isInBoard(int y, int x) {
	if (y > -1 && y < r)
		if (x > -1 && x < c)
			return true;
	return false;
}