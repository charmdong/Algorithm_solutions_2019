/**
 * @author : donggun.chung
 * @date : 2020.02.22
 * @site : BOJ
 * @prob_Info : 13913 숨바꼭질 4 
 * @time : 12ms
 * @memory : 3680KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<int> dist, before;
vector<bool> visited;

void bfs();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	dist.assign(100001, 0);
	before.assign(100001, 0);
	visited.assign(100001, false);

	bfs();

	return 0;
}

void bfs() {
	if (N == K) {
		cout << 0 << endl;
		cout << K << endl;
		return;
	}

	vector<int> res;
	queue<int> q;

	visited[N] = true;
	q.push(N);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == K) {
			cout << dist[now] << endl;

			res.push_back(now);
			int prev = before[now];
			while (true) {
				if (prev == N) {
					res.push_back(prev);
					break;
				}

				res.push_back(prev);
				prev = before[prev];
			}

			for (auto iter = res.rbegin(); iter != res.rend(); iter++) {
				cout << *iter << " ";
			}
			cout << endl;

			return;
		}

		for (int next : {now - 1, now + 1, now * 2}) {
			if (next >= 0 && next <= 100000) {
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
					dist[next] = dist[now] + 1;
					before[next] = now;
				}
			}
		}
	}
}