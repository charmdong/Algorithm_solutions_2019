// 스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans=987654321;
int map[20][20];
bool visited[20];

void dfs(int index, int cnt=0);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];
	
	dfs(0, 0);
	cout << ans << endl;

	return 0;
}

void dfs(int index, int cnt) {
	if (cnt == N / 2) {
		vector<int> start, link;
		for (int i = 0; i < N; i++)
			visited[i] ? start.push_back(i) : link.push_back(i);

		int sum1 = 0;
		for (int i : start)
			for (int j : start) 
				sum1 += map[i][j];
		
		int sum2 = 0;
		for (int i : link) 
			for (int j : link) 
				sum2 += map[i][j];
		
		ans = min(ans, abs(sum1 - sum2));
		return;
	}

	for (int i = index; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i + 1, cnt + 1);
		visited[i] = false;
	}
}