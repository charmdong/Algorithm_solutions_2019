#include <iostream>
#include <algorithm>
using namespace std;

int ans=99999;
int N, M, H; // 세로선, 가로선의 개수, 가로선을 놓을 수 있는 위치의 개수
int ladder[31][11];

bool check();
void dfs(int index=1, int cnt=0);

int main()
{
	int a, b;
	cin >> N >> M >> H;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	dfs();
	if (ans > 3) ans = -1;
	cout << ans << endl;

	return 0;
}

bool check() {
	for (int start = 1; start <= N; start++) {
		int end = start;
		for (int row = 1; row <= H; row++) {
			int left = ladder[row][end - 1]; // 이전 세로선으로 가는 사다리
			int right = ladder[row][end]; // 다음 세로선으로 가는 사다리

			if (left) end--;
			if (right) end++;
		}
		if (start != end)
			return false;
	}
	return true;
}

void dfs(int index, int cnt) {
	if (cnt > 3) return;
	
	if (check()) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = 1; i < N; i++) { // i -> i+1로 가는 가로선만 만드는 거니까 
		for (int j = index; j <= H; j++) {// 다음 가로선에 대해서 진행해야하기 때문에
			if (ladder[j][i] || ladder[j][i - 1] || ladder[j][i + 1]) // 가로선은 연속될 수 없다.
				continue;

			ladder[j][i] = 1;
			dfs(j, cnt + 1);
			ladder[j][i] = 0;
		}
	}
}