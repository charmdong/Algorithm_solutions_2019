#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int n;
int dp[MAX + 1];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		dp[i] = i;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j*j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	cout << dp[n] << endl;
	return 0;
}