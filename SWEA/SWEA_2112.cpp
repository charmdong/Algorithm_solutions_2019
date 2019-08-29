// 보호 필름
#include <iostream>
#include <algorithm>
using namespace std;

int D, W, K, ans;
int film[13][20], copied[13][20];
bool visited[13];
bool isGood();
void input(int d, int val);
void recover(int d);
void dfs(int m, int limit, int index);

int main()
{
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		cin >> D >> W >> K;
		for (int j = 0; j < D; j++) {
			for (int k = 0; k < W; k++) {
				cin >> film[j][k];
				copied[j][k] = film[j][k];
			}
		}
		ans = 14;
		if (K == 1)
			ans = 0;
		else {
			for (int i = 0; i <= K; i++) {
				dfs(0, i, 0);
				if (ans < 14)
					break;
			}
		}
		cout << "#" << i << " " << ans << endl;
	}
	return 0;
}

bool isGood() {
	int check = 0;
	for (int i = 0; i < W; i++) {
		int cnt = 1;
		for (int j = 0; j < D; j++) {
			if (cnt >= K) {
				check++;
				break;
			}
			if (j < D - 1) {
				if (copied[j][i] == copied[j + 1][i])
					cnt++;
				else
					cnt = 1;
			}
		}
		if (check != (i + 1)) return false;
	}
	return true;
}

void input(int d, int val) {
	for (int i = 0; i < W; i++)
		copied[d][i] = val;
}

void recover(int d) {
	for (int i = 0; i < W; i++)
		copied[d][i] = film[d][i];
}

void dfs(int m, int limit, int index) { // m : 투약 횟수 limit : 투약 최대 횟수
	if (m == limit) {
		if (isGood()) 
			ans = min(ans, m);
		return;
	}

	for (int i = index; i < D; i++) {
		for (int j = 0; j < 2; j++) {
			input(i, j);
			dfs(m + 1, limit, i + 1);
			recover(i);
		}
	}
}