#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> ary, dp;

int main()
{
	int ans = -1000;
	cin >> n;
	ary.assign(n + 1, 0);
	dp.assign(n + 1, 0);

	for (int i = 0; i < n; i++)
		cin >> ary[i + 1];

	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + ary[i], ary[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	//cout << *max_element(dp.begin()+1, dp.end()) << endl;

	return 0;
}