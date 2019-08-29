// 로봇 청소기
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

	visited[y][x] = true; // 현재 위치 청소
	// 왼쪽으로 한칸 간 좌표
	int ny = y + dy[(dir + 3) % 4];
	int nx = x + dx[(dir + 3) % 4];

	if (isInMap(ny, nx)) {
		if (map[ny][nx] == 0) {
			if (!visited[ny][nx]) // 왼쪽에 청소할 공간이 존재하는 경우
				return solution(ny, nx, (dir + 3) % 4, clean + 1);
			else { // 왼쪽에 청소할 공간이 존재하지 않는 경우
				return case3(y, x, dir) ?
					solution(y + dy[(dir + 2) % 4], x + dx[(dir + 2) % 4], dir, clean) : // 3번의 경우
					solution(y, x, (dir + 3) % 4, clean); // 2번의 경우
			}
		}
		else { // 왼쪽이 벽인 경우
			return case3(y, x, dir) ?
				solution(y + dy[(dir + 2) % 4], x + dx[(dir + 2) % 4], dir, clean) : // 3번의 경우
				solution(y, x, (dir + 3) % 4, clean); // 2번의 경우
		}
	}
}

bool case3(int y, int x, int dir) {
	if (!visited[y + dy[(dir + 2) % 4]][x + dx[(dir + 2) % 4]]) // 뒤에 청소할 공간이 있는 경우
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
	if (map[y + dy[(dir + 2) % 4]][x + dx[(dir + 2) % 4]] == 0) // 뒤가 벽이 아닌 경우
		return false;

	int range[3] = { 0,1,3 }; // 앞, 좌, 우에 대하여
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