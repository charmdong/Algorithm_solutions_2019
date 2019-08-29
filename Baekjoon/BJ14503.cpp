// �κ� û�ұ�
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50
using namespace std;

int N, M;
int ry, rx, dir;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int map[MAX][MAX];
bool visited[MAX][MAX];

int solution(int y, int x, int dir, int area=1);
bool isInMap(int y, int x);
bool case3(int y, int x, int dir);
bool case4(int y, int x, int dir);

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> ry >> rx >> dir;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	cout << solution(ry, rx, dir) << endl;
	
	return 0;
}

int solution(int y, int x, int dir, int clean) {
	if (case4(y, x, dir))
		return clean;

	visited[y][x] = true; // ���� ��ġ û��
	// �������� ��ĭ �� ��ǥ
	int ny = y + dy[(dir + 3) % 4];
	int nx = x + dx[(dir + 3) % 4];

	if (isInMap(ny, nx)) {
		if (map[ny][nx] == 0) {
			if (!visited[ny][nx]) // ���ʿ� û���� ������ �����ϴ� ���
				return solution(ny, nx, (dir + 3) % 4, clean + 1);
			else { // ���ʿ� û���� ������ �������� �ʴ� ���
				return case3(y, x, dir) ?
					solution(y + dy[(dir + 2) % 4], x + dx[(dir + 2) % 4], dir, clean) : // 3���� ���
					solution(y, x, (dir + 3) % 4, clean); // 2���� ���
			}
		}
		else { // ������ ���� ���
			return case3(y, x, dir) ?
				solution(y + dy[(dir + 2) % 4], x + dx[(dir + 2) % 4], dir, clean) : // 3���� ���
				solution(y, x, (dir + 3) % 4, clean); // 2���� ���
		}
	}
}

bool case3(int y, int x, int dir) {
	if (!visited[y + dy[(dir + 2) % 4]][x + dx[(dir + 2) % 4]]) // �ڿ� û���� ������ �ִ� ���
		return false;

	int range[3] = { 0,1,3 };
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[(dir + range[i]) % 4];
		int nx = x + dx[(dir + range[i]) % 4];

		if (isInMap(ny, nx)) {
			if (map[ny][nx] == 0)
				if (!visited[ny][nx])
					return false;
		}
	}

	return true;
}

bool case4(int y, int x, int dir) {
	if (map[y + dy[(dir + 2) % 4]][x + dx[(dir + 2) % 4]] == 0) // �ڰ� ���� �ƴ� ���
		return false;

	int range[3] = { 0,1,3 }; // ��, ��, �쿡 ���Ͽ�
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[(dir + range[i]) % 4];
		int nx = x + dx[(dir + range[i]) % 4];

		if (isInMap(ny, nx)) {
			if (map[ny][nx] == 0)
				if (!visited[ny][nx])
					return false;
		}
	}

	return true;
}

bool isInMap(int y, int x) {
	if (y > -1 && y < N)
		if (x > -1 && x < M)
			return true;
	return false;
}