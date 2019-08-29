// 시간 초과 때문에, 좌표를 입력 받은 후 갈 수 있는 얘들만 걸러낸다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;

short test, n;
vector<int> map[MAX + 2];
bool visited[MAX + 2]; 

void dfs(int index=0);

int main()
{
	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> n;

		int y, x;
		vector<pair<int, int>> pos;
		for (int j = 0; j < n + 2; j++) {
			cin >> y >> x;
			pos.push_back({ y,x });
		}

		for (int j = 0; j < n + 1; j++) { // 갈 수 있는 편의점만 걸러내기
			for (int k = j + 1; k < n + 2; k++) {
				if (abs(pos[j].first - pos[k].first) + abs(pos[j].second - pos[k].second) <= 1000) {
					map[j].push_back(k);
					map[k].push_back(j);
				}
			}
		}

		dfs();
		cout << (visited[n + 1] ? "happy\n" : "sad\n");
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < n + 2; j++)
			map[j].clear();
	}
	return 0;
}

void dfs(int index) {
	visited[index] = true;
	
	if (index == n + 1)
		return;

	for (int i = 0; i < map[index].size(); i++) {
		int next = map[index][i];
		if (!visited[next])
			dfs(next);
	}
}