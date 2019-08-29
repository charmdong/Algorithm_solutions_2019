// 2048 (Easy)
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define LIMIT 5
using namespace std;

int N, ans;
int board[20][20];
bool crashed[20][20];

void action(int direct);
void dfs(int moveCnt=0);
void copy(int (*p)[20], bool recover=false);
int getMaxValue();

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> board[i][j];	
	dfs();
	cout << ans << endl;
	return 0;
}

void action(int dir) {
	for (int i = 0; i < N; i++) {
		queue<int> q; // 각 행 또는 열의 재배치를 위해 사용할 큐
		if (dir == 0) { // UP
			for (int j = 1; j < N; j++) {
				if (board[j][i] == 0) continue;
				int num = board[j][i];
				for (int k = j - 1; k >= 0; k--) {
					if (board[k][i] == 0) continue;
					if (board[k][i] != num || crashed[k][i]) break;
					board[k][i] *= 2;
					crashed[k][i] = true;
					board[j][i] = 0;
					break;
				}
			}
			for (int j = 0; j < N; j++) {
				if (board[j][i] == 0) continue;
				q.push(board[j][i]);
				board[j][i] = 0;
			}
			int index = 0;
			while (!q.empty()) {
				board[index++][i] = q.front(); q.pop();
			}
		}
		else if (dir == 1) { // DOWN
			for (int j = N-2; j >= 0; j--) {
				if (board[j][i] == 0) continue;
				int num = board[j][i];
				for (int k = j + 1; k < N; k++) {
					if (board[k][i] == 0) continue;
					if (board[k][i] != num || crashed[k][i]) break;
					board[k][i] *= 2;
					crashed[k][i] = true;
					board[j][i] = 0;
					break;
				}
			}
			for (int j = N-1; j >=0; j--) {
				if (board[j][i] == 0) continue;
				q.push(board[j][i]);
				board[j][i] = 0;
			}
			int index = N-1;
			while (!q.empty()) {
				board[index--][i] = q.front(); q.pop();
			}
		}
		else if (dir == 2) { // LEFT
			for (int j = 1; j < N; j++) {
				if (board[i][j] == 0) continue;
				int num = board[i][j];
				for (int k = j - 1; k >= 0; k--) {
					if (board[i][k] == 0) continue;
					if (board[i][k] != num || crashed[i][k]) break;
					board[i][k] *= 2;
					crashed[i][k] = true;
					board[i][j] = 0;
					break;
				}
			}
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) continue;
				q.push(board[i][j]);
				board[i][j] = 0;
			}
			int index = 0;
			while (!q.empty()) {
				board[i][index++] = q.front(); q.pop();
			}
		}
		else { // RIGHT
			for (int j = N-2; j >= 0; j--) {
				if (board[i][j] == 0) continue;
				int num = board[i][j];
				for (int k = j +1; k < N; k++) {
					if (board[i][k] == 0) continue;
					if (board[i][k] != num || crashed[i][k]) break;
					board[i][k] *= 2;
					crashed[i][k] = true;
					board[i][j] = 0;
					break;
				}
			}
			for (int j = N-1; j >= 0; j--) {
				if (board[i][j] == 0) continue;
				q.push(board[i][j]);
				board[i][j] = 0;
			}
			int index = N-1;
			while (!q.empty()) {
				board[i][index--] = q.front(); q.pop();
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt >= LIMIT) {
		ans = max(ans, getMaxValue());
		return;
	}

	int origin[20][20];
	for (int d = 0; d < 4; d++) {
		copy(origin);
		action(d); // 밀고
		memset(crashed, false, sizeof(crashed));
		dfs(cnt + 1); 
		copy(origin, true);
	}
}

void copy(int (*origin)[20], bool recover) {
	if (recover) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = origin[i][j];
	}
	else {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				origin[i][j] = board[i][j];
	}
}

int getMaxValue() {
	int res=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > res)
				res = board[i][j];
		}
	}
	return  res;
}