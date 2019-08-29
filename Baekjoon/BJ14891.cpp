//Åé´Ï¹ÙÄû
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int gear[4][8];
bool visited[4];
int K, gNum, dir;
void dfs(int now, int dir);
void rotate(int n, int d);
int answer();

int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);
	
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> gNum >> dir;
		dfs(gNum - 1, dir);
		memset(visited, false, sizeof(visited));
	}

	cout << answer() << endl;
	return 0;
}

void dfs(int now, int dir) {
	visited[now] = true;

	int prev = now - 1;
	int next = now + 1;

	if (prev > -1 && !visited[prev]) {
		if (gear[prev][2] != gear[now][6])
			dfs(prev, dir*-1);
	}

	if (next < 4 && !visited[next]) {
		if (gear[now][2] != gear[next][6])
			dfs(next, dir*-1);
	}
	rotate(now, dir);
}

void rotate(int n, int d) {
	if (d == -1) {
		int tmp = gear[n][0];
		for (int i = 1; i < 8; i++)
			gear[n][i - 1] = gear[n][i];
		gear[n][7] = tmp;
	}
	else {
		int tmp = gear[n][7];
		for (int i = 6; i >= 0; i--)
			gear[n][i + 1] = gear[n][i];
		gear[n][0] = tmp;
	}
}

int answer() {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1)
			ans += pow(2, i);
	}
	return ans;
}