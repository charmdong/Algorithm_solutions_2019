#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

int f, start, goal, up, down;
int dist[MAX + 1];
int bfs(int start, int goal);

int main()
{
	cin >> f >> start >> goal >> up >> down;
	int res = bfs(start, goal);
	
	if (res != -1)
		cout << res << endl;
	else
		cout << "use the stairs" << endl;

	return 0;
}

int bfs(int start, int goal) {
	queue<int> q;

	q.push(start);
	dist[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == goal)
			return dist[goal]-1;

		int goDown = now - down;
		int goUp = now + up;

		if (goDown >= 1 && !dist[goDown]) {
			dist[goDown] = dist[now] + 1;
			q.push(goDown);
		}

		if (goUp <= f && !dist[goUp]) {
			dist[goUp] = dist[now] + 1;
			q.push(goUp);
		}
	}
	return -1; // 0을 반환하면 안되는 이유 : 시작 층이 목표 층과 같은 경우가 존재.
}