// 벌꿀채취
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C, ans, power;
int honey[10][10];
vector<pair<int, int>> pos;

void dfs(int y=0, int x=0, int cnt=0);
void getCost(int y, int x, int cnt, int sum, int cost);

int main()
{
	int test;
	cin >> test;

	for (int i = 1; i <= test; i++) {
		cin >> N >> M >> C;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cin >> honey[j][k];
		dfs();
		cout << "#" << i << " " << ans << endl;
		ans = 0;
	}
	return 0; 
}

void dfs(int y,int x, int cnt) {
	if (cnt == 2) {
		int total = 0;
		for (int i = 0; i < 2; i++) { // 2개의 좌표에 대하여
			getCost(pos[i].first, pos[i].second, 0, 0, 0);
			total += power;
			power = 0;
		}
		ans = max(ans, total);
		return;
	}

	for (int i = y; i < N; i++) {
		if (x >= N) {
			x = 0;
			continue;
		}
		for (int j = x; j < N; j++) { // 같은 라인에서 좌표를 뽑을 수 있는 경우
			if (j + M > N) {  // 다음 행으로 넘어가야하기 때문에
				x = 0;
				break; 
			}
			pos.push_back({ i,j });
			dfs(i, j + M, cnt + 1);
			pos.pop_back();
		}
	}
}

void getCost(int y, int x, int cnt, int sum, int cost) { // 이게 핵심이다 진심
	if (sum > C) return;
	power = max(power, cost);
	if (cnt == M) return;

	getCost(y, x + 1, cnt + 1, sum + honey[y][x], cost + (honey[y][x] * honey[y][x]));
	getCost(y, x + 1, cnt + 1, sum, cost);
}