#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 20
using namespace std;

int n;
int sharkSize=2, eatNum;
int dy[4] = { -1,0,0,1};
int dx[4] = { 0,-1, 1,0 };
pair<int, int> shark;
int map[MAX][MAX];
bool visited[MAX][MAX];

int bfs(int y = shark.first, int x =shark.second);
bool isInMap(int y, int x);

class fish {
public:
	int y, x, d;
	fish(int y=20, int x=20, int d=0) :y(y), x(x), d(d) {}
	void operator=(fish &b) {
		this->y = b.y;
		this->x = b.x;
		this->d = b.d;
	}
};

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)
				shark = { i,j };
		}
	}
	
	cout << bfs() << endl;

	return 0;
}

int bfs(int y, int x) { // ���� �� �ִ� ��������� �����ϴ� �� �ɸ��� �ð� ���
	int ans = 0;

	while (1) {
		queue<fish> q;
		vector<fish> fishes;
		
		visited[shark.first][shark.second] = true;
		q.push(fish(shark.first, shark.second, 0));

		int found = -1; // bfs������ ���� ��ǥ�� ���� ������ ť�� �����ϱ� ������, �̸� �̿��� ���� �ߴ�.
		while (!q.empty()) {
			fish now = q.front(); q.pop();

			if (found == now.d) break;

			for (int i = 0; i < 4; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				// ������ �� �ִ� ĭ�� ��� (Ư�� �Ÿ� �̻� ������ ��������)
				if (isInMap(ny, nx) && !visited[ny][nx] && map[ny][nx] <= sharkSize) {
					visited[ny][nx] = true;
					// ���� �� �ִ� ������� ���, ���� �Ÿ��� �ִ�.
					if (map[ny][nx] > 0 && map[ny][nx] < sharkSize) {
						found = now.d + 1;
						fishes.push_back(fish(ny, nx, now.d + 1));
					}
					q.push(fish(ny, nx, now.d + 1));
				}
			}
		}
		
		fish eat;
		if (found == -1) break; // ���� �� �ִ� ����Ⱑ ���� ���
		else {
			if (fishes.size() > 1) {
				for (auto t : fishes) {
					if (t.y < eat.y)
						eat = t;
					else if (t.y == eat.y) {
						if (t.x < eat.x)
							eat = t;
					}
					else continue;
				}
			}
			else
				eat = fishes[0];
		}
		if (found != -1) {
			ans += found;
			map[shark.first][shark.second] = 0;
			map[eat.y][eat.x] = 9;
			shark = { eat.y,eat.x };
			if (sharkSize == ++eatNum) {
				sharkSize++;
				eatNum = 0;
			}
		}
		memset(visited, false, sizeof(visited));
	}

	return ans;
}

bool isInMap(int y, int x) {
	if (y > -1 && y < n)
		if (x > -1 && x <n)
			return true;
	return false;
}