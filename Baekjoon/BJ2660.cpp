/**
 * @author : donggun.chung
 * @date : 2020.02.16
 * @site : BOJ
 * @prob_Info : 2660 회장뽑기 
 * @time : 0ms
 * @memory : 1988KB
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> dist;
vector<int> score;

void solution();
int bfs(int start);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	graph.assign(N + 1, vector<int>());
	score.assign(N + 1, 0);
	score[0] = 50;

	int src, des;
	while (true) {
		cin >> src >> des;

		if (src < 0) break;

		graph[src].push_back(des);
		graph[des].push_back(src);
	}

	for (int index = 1; index <= N; index++) {
		score[index] = bfs(index);
	}

	solution();

	return 0;
}

void solution() {
	vector<int> minIndex;
	int minScore = *min_element(score.begin(), score.end());
	
	for (int index = 1; index <= N; index++) {
		if (score[index] == minScore) {
			minIndex.push_back(index);
		}
	}

	cout << minScore << " "<< minIndex.size() << endl;
	for (int index : minIndex) {
		cout << index << " ";
	}
	cout << endl;
}

int bfs(int start) {
	int answer = 0;

	dist.assign(N + 1, 0);
	queue<int> q;
	vector<bool> visited(N + 1, false);

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int index = 0; index < graph[now].size(); index++) {
			int next = graph[now][index];

			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				answer = dist[next] = dist[now] + 1;
			}
		}
	}

	return answer;
}