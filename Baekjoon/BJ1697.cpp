#include <iostream>
#include <queue>
#define MIN 0
#define MAX 100000
using namespace std;

int visited[MAX + 1];
int BFS(int n, int k);

int main()
{
	int x, k;
	cin >> x >> k;
	cout << BFS(x, k);

	return 0;
}

int BFS(int n, int k) {
	queue<int> q;
	
	q.push(n);
	visited[n] = 1;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		
		if (tmp == k) return visited[tmp]-1;
		if (tmp - 1 >= MIN && visited[tmp - 1] == 0) {
			visited[tmp - 1] = visited[tmp]+1;
			q.push(tmp - 1);
		}
		if (tmp + 1 <= MAX && visited[tmp + 1] == 0) {
			visited[tmp + 1] = visited[tmp]+1;
			q.push(tmp + 1);
		}
		if (tmp * 2 >= MIN && tmp * 2 <= MAX && visited[tmp * 2] == 0) {
			visited[tmp * 2] = visited[tmp] + 1;
			q.push(tmp * 2);
		}
	}
}