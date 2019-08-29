/* Do not solve this problem with BST. You have to solve this problem with DFS.
	So, This Problem has a indirect graph.
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX 10000
using namespace std;

class node {
public:
	int d, w;
	node(int des, int weight) : d(des), w(weight) {}
};

int n;
vector<node> board[MAX+1];
vector<bool> visited;
int ans;
int endPoint;

void dfs(int root, int len=0);

int main()
{
	int s, d, w;
	cin >> n;

	visited.assign(n + 1, false);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &s, &d, &w);
		board[s].push_back(node(d, w));
		board[d].push_back(node(s, w));
	}

	dfs(1);

	ans = 0;
	visited.assign(n + 1, false);

	dfs(endPoint);
	cout << ans << endl;

	return 0;
}

void dfs(int root, int len) {
	if (visited[root])
		return;

	visited[root] = true;
	if (ans < len) {
		ans = len;
		endPoint = root;
	}

	for (int i = 0; i < board[root].size(); i++)
		dfs(board[root][i].d, board[root][i].w + len);
}