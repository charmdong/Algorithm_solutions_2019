#include <iostream>
#include <vector>
#include <string>
#define MAX 1000
using namespace std;

int n, k;
int board[MAX + 1][MAX + 1];
int visited[MAX + 1];
vector<string> codes;
vector<int> res;

int hmDistance(int s, int d);
void dfs(int src, int des);

int main()
{
	int s, d;
	cin >> n >> k;
	codes.assign(n + 1,"");
	
	for (int i = 0; i < n; i++) 
		cin >> codes[i + 1];

	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp = hmDistance(i, j);
			if (tmp == 1)
				board[i][j] = board[j][i] = tmp;
			//cout << board[i][j] << " ";
		}
		//cout << endl;
	}
	cin >> s >> d;

	dfs(s, d);
	if (res.size() == 0)
		cout << "-1\n";

	return 0;
}

int hmDistance(int s, int d) {
	int cnt = 0;

	for (int i = 0; i < k; i++) {
		if (codes[s][i] != codes[d][i])
			cnt++;
	}

	return cnt;
}

void dfs(int src, int des) {
	visited[src] = 1;
	res.push_back(src);
	if (src == des) {
		for (int t : res)
			cout << t << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (board[src][i] == 1 && !visited[i]) { // 인접하고, 방문하지 않은 경우
			dfs(i, des);
		}
	}
	res.pop_back();
}