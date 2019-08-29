// 숫자 만들기
#include <iostream>
#include <algorithm>
#define MAX 12
using namespace std;

int big, small;
int n;
int digit[MAX];
int pl, mi, mul, di;

void dfs(int index, int value, int p, int s, int m, int d);

int main()
{
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		big = -1000000001;
		small = 1000000001;
		cin >> n;
		cin >> pl >> mi >> mul >> di;
		for (int j = 0; j < n; j++)
			cin >> digit[j];
		dfs(0, digit[0], pl, mi, mul, di);
		cout << "#" << i << " " << big - small << endl;
	}

	return 0;
}

void dfs(int index, int value, int p, int s, int m, int d) {
	if (index == n-1) {
		big = max(big, value);
		small = min(small, value);
	}
	
	if (p > 0)
		dfs(index + 1, value + digit[index + 1], p - 1, s, m, d);
	if (s > 0)
		dfs(index + 1, value - digit[index + 1], p, s - 1, m, d);
	if (m > 0)
		dfs(index + 1, value * digit[index + 1], p, s, m - 1, d);
	if (d > 0)
		dfs(index + 1, value / digit[index + 1], p, s, m, d - 1);
}