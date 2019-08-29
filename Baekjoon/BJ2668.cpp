#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int n;
int board[MAX + 1], cycle[MAX+1];
bool visited[MAX + 1];
vector<int> res;

void dfs(int start, int now);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i + 1];

	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i, i);
	}

	cout << res.size() << "\n";
	sort(res.begin(), res.end());
	for (auto t : res)
		cout << t << "\n";

	return 0;
}

void dfs(int start, int now) {
	visited[now] = true;
	cycle[now] = start;

	int next = board[now];

	if (!visited[next]) // CASE : the next index is visited.
		dfs(start, next);
	else { // CASE : the next index isn't visited.
		if (start == next) {
			for (int i = 1; i <= n; i++) {
				if (cycle[i] == start)
					res.push_back(i);
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (cycle[i] == start)
					visited[i] = false;
			}
		}
	}
}