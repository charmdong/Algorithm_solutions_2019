#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define MIN 1000
#define MAX 10000
using namespace std;

bool isPrime[MAX];
int dist[MAX];

int bfs(string start, string goal);

int main() {
	memset(isPrime, true, MAX);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j < MAX; j += i)
				isPrime[j] = false;
		}
	}
	
	int testCase;
	string before, after;

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> before >> after;
		int res = bfs(before, after);
		if (res == -1)
			cout << "Impossible\n";
		else
			cout << res << endl;
		memset(dist, 0, sizeof(dist));
	}

	return 0;
}

int bfs(string before, string after) {
	if (before == after) return 0;

	queue<string> q;
	q.push(before);
	dist[stoi(before)] = 1;

	while (!q.empty()) {
		string now = q.front();
		int nowInt = stoi(now);
		q.pop();

		if (now == after) return dist[nowInt] - 1;

		for (int i = 0; i < now.length(); i++) {
			string next = now;
			for (int j = 0; j < 10; j++) {
				if (next[i] - '0' != j) {
					next[i] = j + '0';
					int nextInt = stoi(next);
					if (nextInt >= MIN && nextInt < MAX && isPrime[nextInt] && dist[nextInt]==0) {
						dist[nextInt] = dist[nowInt] + 1;
						q.push(next);
					}
				}
			}
		}
	}

	return -1;
}