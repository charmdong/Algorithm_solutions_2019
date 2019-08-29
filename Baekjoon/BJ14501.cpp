#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;

int n, ans;
int time[MAX + 1];
int price[MAX + 1];
void solution(int day = 1, int profit = 0);
void dfs(int start = 1, int profit = 0);

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> time[i] >> price[i];

	//solution();
	dfs();
	cout << ans << endl;

	return 0;
}

void solution(int day, int profit) {
	if (day == n + 1) {
		if (ans < profit)
			ans = profit;
		return;
	}
	if (day > n + 1) return;
	solution(day + time[day], profit + price[day]);
	solution(day + 1, profit);
}

void dfs(int day, int profit) {
	if (day == n + 1) {
		ans = (ans < profit) ? profit : ans;
		return;
	}

	for (int i = day; i <= n; i++) {
		if (day + time[i] > n + 1)
			dfs(i + 1, profit);
		else
			dfs(i + time[i], profit + price[i]);
	}
}