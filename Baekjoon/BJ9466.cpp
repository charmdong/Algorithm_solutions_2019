#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> st;
vector<int> visited;
vector<int> cycle;
int n;

int dfs(int start, int now, int dep=1);

int main()
{
	int testCase;
	scanf("%d", &testCase);
	
	while (testCase--) {
		int team = 0;
		scanf("%d", &n);

		st.assign(n + 1, 0);
		visited.assign(n + 1, 0);
		cycle.assign(n + 1, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &st[i + 1]);

		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0)
				team += dfs(i, i);
		}
		printf("%d\n", n-team);
	}
	return 0; 
}

int dfs(int start, int now, int dep) {
	visited[now] = dep;
	cycle[now] = start; // �����κ��� ���۵� ����Ŭ���� Ȯ���ϱ� ����.

	int next = st[now];

	if (visited[next] == 0) // ���� �л��� �湮���� ���� ���
		return dfs(start, next, dep + 1);
	else  // ���� �л��� �湮�Ǿ��� �ִ� ���.
		return (start == cycle[next]) ? dep - visited[next] + 1 : 0;
}