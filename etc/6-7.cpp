/// �˰��� �����ذ����� 6-7(����) : �����ϴ� ���ǿ� ����
/// 2<= n <= 10���� ���ð� �����ϴµ�, �� ���ÿ��� ����� �ٸ� ���õ��� �� ���� �湮�� �� ����� ���÷� ���ƿ��� �ּ� �Ÿ��� ���϶�.

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
		if (path.size() == n) return currentLength + dist[path[0]][path.back()]; // �������� ������ ���ÿ� ����� ������ �Ÿ��� ������ ���� ��ȯ.
		
		double ret = INT_MAX;

		for (int next = 0; next < n; next++) {
				if (visited[next]) continue; // �湮�� ������ ��� ���� ���ÿ� ���� ����.
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