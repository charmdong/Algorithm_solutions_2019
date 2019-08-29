#include <iostream>
#include <vector>
using namespace std;

int dp[31];
int solution(int n);

int main()
{
	int n;
	cin >> n;	
	cout << solution(n) << endl;
	return 0;
}

int solution(int n) {
	dp[0] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += 2 * dp[j];
	}
	
	return dp[n];
}