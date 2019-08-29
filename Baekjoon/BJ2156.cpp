#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000
using namespace std;

int ary[MAX + 1], dp[MAX + 1];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> ary[i+1];

	dp[1] = ary[1];
	if(n > 1)
		dp[2] = ary[1] + ary[2];
	
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + ary[i], dp[i - 3] + ary[i - 1] + ary[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n] << endl;

	return 0;
}