#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> computers);
void dfs(int s, vector<int> &visited, vector<vector<int>> computers);

int main()
{
	int n = 3;
	vector<vector<int>> computers = { {1,1,0},{1,1,1},{0,1,1} };
	cout << solution(n, computers) << endl;
	return 0;
}

int solution(int n, vector<vector<int>> computers) {
	int ans = 0;
	vector<int> visited(n, 0);

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			ans++;
			dfs(i, visited,computers);
		}
	}

	return ans;
}

void dfs(int s, vector<int> &visited, vector<vector<int>> computers) {
	visited[s] = 1;

	for (int i = 0; i < visited.size(); i++) {
		if (s != i && !visited[i] && computers[s][i]) // i is not s, i didn't visited, and computers[s][i] is connected.
			dfs(i, visited, computers);
	}
}	