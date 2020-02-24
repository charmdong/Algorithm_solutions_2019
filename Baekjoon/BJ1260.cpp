#include <iostream>
#include <vector>
#include <queue>
#define N 1000
#define M 10000
using namespace std;

void DFS(int start);
void BFS(int start);

int n, m;
int graph[N + 1][N + 1];
vector<int> visited;

int main()
{
	int start ,src, des;
	cin >> n >> m >> start;

	visited.assign(n+1, 0); // ���� ������ŭ visited �迭 �ʱ�ȭ

	for (int i = 0; i < m; i++) {
		cin >> src >> des;
		graph[src][des] = graph[des][src] =  1;
	}

	DFS(start);
	cout << endl;
	BFS(start);

	return 0;
}

void DFS(int start) {
	visited[start] = 1;
	cout << start << " ";

	for (int i = 1; i <= n; i++) {
		if (graph[start][i] != 0 && visited[i] == 0) {
			DFS(i);
		}
	}
} // recursive

void BFS(int start) { // iterative
	queue<int > q;
	int tmp;

	visited.assign(n + 1, 0);

	visited[start] = 1;
	q.push(start);
	
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		
		cout << tmp << " ";

		for (int i = 1; i <= n; i++) {
			if (graph[tmp][i] != 0 && visited[i] == 0) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	
	cout << endl;
}