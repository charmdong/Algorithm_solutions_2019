// �ֻ��� ������
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
	// �̵��� ĭ�� ��ǥ
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (isInMap(ny, nx)) { // �̵��� �� �ִ� ��ġ�� ���
		rotate(dir); // �� �������� �ֻ����� ������.
		if (map[ny][nx] == 0)
			map[ny][nx] = dice[BOT];
		else {
			dice[BOT] = map[ny][nx];
			map[ny][nx] = 0;
		}
		sy = ny, sx = nx; // �ֻ��� ��ġ ����
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