/// 알고리즘 문제해결전략 6-7(예제) : 여행하는 외판원 문제
/// 2<= n <= 10개의 도시가 존재하는데, 한 도시에서 출발해 다른 도시들을 한 번씩 방문한 뒤 출발한 도시로 돌아오는 최소 거리를 구하라.

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define MAX 10
using namespace std;

int n;
double dist[MAX][MAX];

double shortestPath(vector<int> & path, vector<bool>& visited, double currentLength);

int main()
{
		double currentLength = 0;

		cin >> n;
		vector<int> path;
		path.push_back(0);
		vector<bool> visited(n, false);
		visited[path.back()] = true;

		for (int i = 0; i < n; i++) {
				for (int k = i + 1; k < n; k++) {
						double distance;
						cin >> distance;
						dist[i][k] = dist[k][i] = distance;
				}
		}

		cout << shortestPath(path, visited, currentLength) << endl;

		return 0;
}

double shortestPath(vector<int> & path, vector<bool>& visited, double currentLength) {
		if (path.size() == n) return currentLength + dist[path[0]][path.back()]; // 마지막에 도착한 도시와 출발한 도시의 거리를 더해준 값을 반환.
		
		double ret = INT_MAX;

		for (int next = 0; next < n; next++) {
				if (visited[next]) continue; // 방문한 도시의 경우 다음 도시에 대해 조사.
				int here = path.back();
				path.push_back(next);
				visited[next] = true;

				double cand = shortestPath(path, visited, currentLength+dist[here][next]);

				ret = min(ret, cand);
				visited[next] = false;
				path.pop_back();
		}

		return ret;
}