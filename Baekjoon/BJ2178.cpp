/// 미로 탐색
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool board[100][100]; // 길
int check[100][100]; // 지나온 길인지 확인 및 특정 위치까지 몇 번만에 도달했는지 확인
int dir[4][2] = { {1,0}, {-1,0},{0,1},{0,-1} };

bool isInBoard(int a, int b);
int solution();

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			int b;
			scanf("%1d", &b);
			if (b == 1)
				board[i][k] = true;
		}
	}

	cout << solution();
	return 0;
}

bool isInBoard(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < m);
}

int solution() {
	int cur_y=0, cur_x=0;

	queue<pair<int, int>> q;
	q.push(pair<int, int>(cur_y, cur_x));
	check[cur_y][cur_x] = 1;

	while (!q.empty()) {
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		if ((cur_y == n) && (cur_x == m)) break;

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dir[i][0];
			int next_x = cur_x + dir[i][1];

			if (isInBoard(next_y, next_x) && check[next_y][next_x] == 0 && board[next_y][next_x]) {
				check[next_y][next_x] = check[cur_y][cur_x] + 1;
				q.push(pair<int, int>(next_y, next_x));
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++)
			cout << check[i][k] << " ";
		cout << "\n";
	}*/

	return check[n - 1][m - 1];
}