#include <iostream>
#include <vector>
using namespace std;

int solution(int n);

int main()
{
	int testCase, n;
	cin >> testCase;

	while(testCase--) {
		cin >> n;
		cout << solution(n) << endl;
	}

	return 0;
}

int solution(int n) {
	vector<int> dp(n + 1, 0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int index = 4; index <= n; index++) {
		dp[index] = dp[index - 1] + dp[index - 2] + dp[index - 3];
	}

	return dp[n];
}