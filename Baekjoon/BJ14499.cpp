// 주사위 굴리기
#include <iostream>
#define TOP 0
#define BOT 5
using namespace std;

int N, M, K;
int sy, sx;
int map[20][20];
int dy[5] = { 0, 0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };
int dice[6];

int solution(int y, int x, int dir);
void rotate(int dir);
bool isInMap(int y, int x);

int main() 
{
	ios::sync_with_stdio(false);

	cin >> N >> M >> sy >> sx >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;
		int res = solution(sy, sx, dir);
		if (res != -1)
			cout << res << endl;
	}

	return 0;
}

void rotate(int dir) {
	int rDir = (dir % 2 == 0) ? dir - 1 : dir + 1;
	int tmp = dice[BOT];
	dice[BOT] = dice[dir];
	dice[dir] = dice[TOP];
	dice[TOP] = dice[rDir];
	dice[rDir] = tmp;
}

int solution(int y, int x, int dir) {
	// 이동할 칸의 좌표
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (isInMap(ny, nx)) { // 이동할 수 있는 위치인 경우
		rotate(dir); // 그 방향으로 주사위를 굴린다.
		if (map[ny][nx] == 0)
			map[ny][nx] = dice[BOT];
		else {
			dice[BOT] = map[ny][nx];
			map[ny][nx] = 0;
		}
		sy = ny, sx = nx; // 주사위 위치 갱신
		return dice[TOP];
	}

	return -1;
}

bool isInMap(int y, int x) {
	if (y > -1 && y < N)
		if (x > -1 && x < M)
			return true;
	return false;
}