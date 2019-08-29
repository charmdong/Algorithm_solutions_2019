#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2100000000
using namespace std;

int ans;
typedef struct pos {
	int x, y;
	bool visited;
}pos;

void dfs(vector<pos> &home, int k, int n, int len, int before);

int main()
{
	int test;
	cin >> test;
	
	for (int i = 1; i <= test; i++) {
		int n;
		ans = MAX;
		cin >> n;
		vector<pos> home(n + 2);

		for (int j = 0; j < n+2; j++) {
			cin >> home[j].y >> home[j].x;
			home[j].visited = false;
		}

		dfs(home, 0, n, 0, 0);
		cout << "#" << i << " " << ans << endl;
	}

	return 0;
}

void dfs(vector<pos> &home, int k, int n, int len, int before) {
	if (k == n) {
		len += (abs(home[1].y - home[before].y) + abs(home[1].x - home[before].x));
		ans = min(ans, len);
		return;
	}

	for (int next = 2; next < home.size(); next++) {
		if (!home[next].visited) {
			home[next].visited = true;
			dfs(home, k + 1, n, len + abs(home[next].y - home[before].y) + abs(home[next].x - home[before].x), next);
			home[next].visited = false;
		}
	}
}