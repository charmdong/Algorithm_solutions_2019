#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int n;
int price[MAX + 1];
int dp[MAX + 1];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> price[i + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + price[j]);
	}

	cout << dp[n] << endl;

	return 0;
}