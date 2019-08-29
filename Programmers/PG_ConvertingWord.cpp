#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <queue>
using namespace std;

vector<int> res;
int solution(string begin, string target, vector < string> words);
void dfs(string begin, string target, vector<string> words, vector<int> &visited, int &ans);
bool canConnected(string s, string e);

int main()
{
	cout << solution("hit", "cog", { "hot","dot","dog","lot","log", "cog"});
	return 0;
}

int solution(string begin, string target, vector<string> words) {
	int ans = 0;
	vector<int> visited(words.size(), 0);
	dfs(begin, target, words, visited, ans);
	if (res.size())
		ans = *min_element(res.begin(), res.end());
	return ans;
}

bool canConnected(string s, string e) {
	int check = 0;

	for (int i = 0; i < s.length(); i++)
		if (s[i] != e[i])
			check++;

	return check == 1 ? true : false;
}

void dfs(string begin, string target, vector<string> words, vector<int> &visited, int &ans) {
	if (begin == target) {
		res.push_back(ans);
		return;
	}

	for (int i = 0; i < words.size(); i++) {
		if (canConnected(begin, words[i]) && !visited[i]) {
			visited[i] = 1;
			ans++;
			dfs(words[i], target, words, visited, ans);
			ans--;
			visited[i] = 0; // back tracking
		}
	}
}

// TO DO bfs with List