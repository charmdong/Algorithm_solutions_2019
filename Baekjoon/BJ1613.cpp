/// Should revise this code to have less time.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 400
using namespace std;

int n, k, testCase;
vector<int> map[MAX + 1];
bool visited[MAX+1];

int dfs(int src, int des);
int bfs(int src, int des);
int solution(int src, int des);

int main()
{
	int s, d;
	cin >> n >> k;
	
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &s, &d);
		map[s].push_back(d);
	}
	
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &s, &d);
		printf("%d\n", solution(s, d));
	}

	return 0;
}

int bfs(int src, int des) {
	queue<int> q;

	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		
		if (now == des) {
			memset(visited, false, sizeof(visited));
			return -1;
		}

		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	memset(visited, false, sizeof(visited));
	return 0;
}

int dfs(int src, int des) { // 두 사건의 전후 관계를 반환 : -1, 0
	visited[src] = true;

	if (src == des) {
		memset(visited, false, sizeof(visited));
		return -1;
	}

	for (int i = 0; i < map[src].size(); i++) {
		int next = map[src][i];

		if (!visited[next])
			return dfs(next, des);
	}
	memset(visited, false, sizeof(visited));
	return 0;
}

int solution(int src, int des) { // 두 사건의 전후 관계를 반환 : -1, 1, 0
	/*int a = bfs(src, des);
	int b = bfs(des, src);
	cout << a << " + " << b << " = " << a - b << endl;
	return a - b;*/
	return bfs(src, des) - bfs(des, src); // -1, 1, 0
}