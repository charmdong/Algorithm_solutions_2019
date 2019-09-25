#include <iostream>
#define MOD 10007
using namespace std;

int dp[1001][10];

int solution(int n);

int main()
{
	int n;

	cin >> n;
	cout << solution(n) << endl;

	return 0;
}

int solution(int n) {
	int ans = 0;

	for (int index = 0; index < 10; index++) {
		dp[1][index] = 1;
	}

	for (int index = 2; index <= n; index++) {
		for(int num = 0; num < 10; num++) {
			for(int last = 0; last <= num; last++) {
				dp[index][num] += (dp[index - 1][last]);
				dp[index][num] %= MOD;
			}
		}
	}

	for(int index = 0; index < 10; index++) {
		ans += (dp[n][index]);
		ans %= MOD;
	}

	return ans;
}