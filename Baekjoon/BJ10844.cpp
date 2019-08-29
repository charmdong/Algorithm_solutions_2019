/// Dynamic Programming : 쉬운 계단 수

#include <iostream>
#define MOD 1000000000
using namespace std;

long dp[101][10]; // 길이가 N인 계단 수를 저장할 변수
long solution(int len);

int main()
{
	int len;
	cin >> len;
	cout << solution(len) << endl;
	return 0;
}

long solution(int len) {
	long res=0;
	// 길이 1의 경우
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= len; i++) {
		for (int k = 0; k <= 9; k++) {
			dp[i][k] = 0;

			if (k == 0)
				dp[i][k] = dp[i - 1][1];
			else if (k == 9)
				dp[i][k] = dp[i - 1][8];
			else
				dp[i][k] = dp[i - 1][k - 1] + dp[i - 1][k + 1];
			
			dp[i][k] %= MOD;
		}
	}

	for (int i = 0; i <= 9; i++)
		res = (res + dp[len][i]) % MOD;
	
	return res;
}