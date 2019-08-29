#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define START "ICN"
#define SRC 0
#define DES 1
using namespace std;

vector<string> solution(vector<vector<string>> tickets);
void dfs(string src, vector<string> &path, vector<vector<string>> tickets);
vector<int> visited;
vector<vector<string>> res;

int main()
{
	vector<string> tmp = solution({ {"ICN","SFO"},{"ICN","ATL"}, {"SFO","ATL"}, {"ATL","ICN"},{"ATL","SFO"} });
	//vector<string> tmp = solution({ {"ICN","JFK"},{"HND","IAD"},{"JFK","HND"} });
	for (auto t : tmp)
		cout << t << " ";
	cout << endl;
	return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> path;
	visited.assign(tickets.size(), 0);
	dfs(START, path, tickets);

	for (auto t : res) {
		for (auto tmp : t)
			cout << tmp << " ";
		cout << endl;
	}
	cout << endl;

	sort(res.begin(), res.end());
	return res[0];
}

void dfs(string src, vector<string> &path, vector<vector<string>> tickets) {
	path.push_back(src);

	if (path.size() - 1 == tickets.size()) {
		res.push_back(path);
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (!visited[i] && tickets[i][SRC] == src) {
			visited[i] = 1;
			dfs(tickets[i][DES], path, tickets);
			path.pop_back();
			visited[i] = 0;
		}
	}
}