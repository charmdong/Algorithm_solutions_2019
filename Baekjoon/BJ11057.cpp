#include <iostream>
using namespace std;

int dp[10][1000];
int solution(int n);

int main()
{
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}

int solution(int n) {
	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;

	for (int j = 2; j <= n; j++) {
		for (int i = 0; i < 10; i++) {
			for (int k = i; k < 10; k++) {
				dp[i][j] += (dp[k][j - 1]) % 10007;
			}
		}
	}

	int total = 0;
	for (int i = 0; i < 10; i++) {
		total += (dp[i][n]);
		total %= 10007;
	}

	return total;
}