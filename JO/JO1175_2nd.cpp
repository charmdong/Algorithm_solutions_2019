#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> dice;

void dfs(int total=0, int cnt = 0);

int main() 
{
	cin >> n >> m;
	dfs();
	return 0;
}

void dfs(int total, int cnt) {
	if (cnt >= n) {
		if (total == m) {
			for (auto t : dice)
				cout << t << " ";
			cout << endl;
			return;
		}
		else
			return;
	}

	for (int i = 1; i <= 6; i++) {
		dice.push_back(i);
		dfs(total + i, cnt + 1);
		dice.pop_back();
	}
}