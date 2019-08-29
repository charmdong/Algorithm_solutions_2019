/*
Solution
1. Build 3 walls in copied map by using recursive function.
2. Infect viruses on copied map.
3. Calculate the best answer.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m, ans;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
int map[MAX][MAX], copiedMap[MAX][MAX];
vector<pair<int, int>> virus;

void bfs();
void mapCopy(int(*)[MAX], int(*)[MAX]);
void buildWall(int wCnt=0);
int zeroCnt(int (*)[MAX]);
bool isInBoard(int y, int x);

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}

	mapCopy(map, copiedMap);
	buildWall();
	cout << ans << endl;
	return 0;
}

void mapCopy(int(*src)[MAX], int(*des)[MAX]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			des[i][j] = src[i][j];
}

void buildWall(int wCnt) {
	if (wCnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j =0; j < m; j++) {
			if (copiedMap[i][j] == 0) {
				copiedMap[i][j] = 1;
				buildWall(wCnt + 1);
				copiedMap[i][j] = 0;
			}
		}
	}
}

void bfs() {
	queue<pair<int,int>> q;
	int tmpMap[MAX][MAX];
	mapCopy(copiedMap, tmpMap);
	
	for (auto t : virus)
		q.push(t);

	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (isInBoard(ny, nx) && tmpMap[ny][nx] == 0 ) {
				tmpMap[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}

	ans = max(ans, zeroCnt(tmpMap));
}

int zeroCnt(int (*cm)[MAX]) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cm[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

bool isInBoard(int y, int x) {
	if (y > -1 && y < n)
		if (x > -1 && x < m)
			return true;
	return false;
}