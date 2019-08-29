// 주사위 던지기
#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[7];
vector<int> dice;
vector<int> usedCnt(6,0);
vector<vector<int>> allCase;

void dfs_1(int cnt = 0);
void dfs_2(int cnt = 0);
void dfs_3(int cnt = 0);

int main()
{
	cin >> n >> m;
	
	switch (m) {
	case 1: dfs_1(); break;
	case 2: dfs_2(); break;
	case 3: dfs_3(); break;
	}

	return 0;
}

void dfs_1(int cnt) {
	if (cnt == n) {
		for (auto t : dice)
			cout << t << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= 6; i++) {
		dice.push_back(i);
		dfs_1(cnt + 1);
		dice.pop_back();
	}
}

void dfs_2(int cnt) {
	if (cnt == n) {
		for (auto t : allCase)
			if (t == usedCnt)
				return;
		allCase.push_back(usedCnt);

		for (auto t : dice)
			cout << t << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= 6; i++) {
		usedCnt[i - 1]++;
		dice.push_back(i);
		dfs_2(cnt + 1);
		dice.pop_back();
		usedCnt[i - 1]--;
	}
	
}

void dfs_3(int cnt) {
	if (cnt == n) {
		for (auto t : dice)
			cout << t << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= 6; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dice.push_back(i);
		dfs_3(cnt + 1);
		dice.pop_back();
		visited[i] = false;
	}
}