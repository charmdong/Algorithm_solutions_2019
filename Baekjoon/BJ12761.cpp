#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int a,b,n,m, ans;
int dist[MAX];
int bfs(int start);
bool isInRange(int x);

int main() {
	cin >> a >> b >> n >> m;
	cout << bfs(n) << endl;
	return 0;
}

int bfs(int start) {
	queue<int> q;

	q.push(start);
	int dx[8] = { 1,-1, a,-a, b,-b, a, b };

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now == m)
			return dist[m];

		for (int i = 0; i < 8; i++) {
			int next;
			if (i > 5)
				next = now*dx[i];
			else
				next = now+dx[i];

			if (isInRange(next)) {
				if (dist[next] == 0) {
					dist[next] = dist[now] + 1;
					q.push(next);
				}
			}
		}
	}

	return -1;
}

bool isInRange(int x) {
	if (x > -1 && x < MAX)
		return true;
	return false;
}