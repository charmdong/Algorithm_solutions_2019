#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, res;
vector<vector<int>> dice;

void solution(int num, int index);

int main()
{
	ios::sync_with_stdio(false);

	cin >> n;
	dice.assign(n, vector<int>(6, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 6; j++)
			cin >> dice[i][j];

	for (int i = 1; i <= 6; i++) { // ù �ֻ����� �Ʒ����� �� �� �ִ� ���
		ans = 0;
		solution(i, 0);
		res = max(res, ans);
	}

	cout << res << endl;

	return 0;
}

void solution(int num, int index) {
	if (index == n)
		return;
	
	int pIndex; // �Ʒ����� �� ��
	for (int i = 0; i < 6; i++) {
		if (dice[index][i] == num) {
			pIndex = i;
			break;
		}
	}

	int tIndex; // ������ �� ���� �ε���
	if (pIndex == 0)
		tIndex = 5;
	else if (pIndex >= 1 && pIndex <= 2)
		tIndex = pIndex + 2;
	else if (pIndex >= 3 && pIndex <= 4)
		tIndex = pIndex - 2;
	else
		tIndex = 0;

	int mVal = 0;
	for (int i = 0; i < 6; i++) {
		if (i == pIndex || i == tIndex) continue;
		mVal = (dice[index][i] > mVal) ? dice[index][i] : mVal;
	}
	ans += mVal;

	solution(dice[index][tIndex], index + 1);
}