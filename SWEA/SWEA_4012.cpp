// 요리사
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 16
using namespace std;

int N, ans;
int meal[MAX][MAX];
bool used[MAX];
vector<int> use;

void dfs(int index = 0, int cnt = 0);

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++) {
		ans = 9999999;
		cin >> N;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cin >> meal[j][k];

		dfs();
		cout << "#" << i+1 << " " << ans << endl;
		memset(used, false, sizeof(used));
	}

	return 0;
}

void dfs(int index, int cnt) {
	if (cnt == N / 2) {
		int sum = 0;
		for (int i = 0; i < use.size(); i++) {
			for (int j = 0; j < use.size(); j++)
				sum += meal[use[i]][use[j]];
		}

		int another = 0;
		for (int i = 0; i < N; i++) {
			if (!used[i]) {
				for (int j = 0; j < N; j++) {
					if (!used[j])
						another += meal[i][j];
				}
			}
		}

		ans = min(ans, abs(sum - another));
		return;
	}

	for (int i = index; i < N; i++) {
		if (!used[i]) {
			used[i] = true;
			use.push_back(i); // 사용된 식재료 번호
			dfs(i+1, cnt + 1);
			use.pop_back();
			used[i] = false;
		}
	}
}