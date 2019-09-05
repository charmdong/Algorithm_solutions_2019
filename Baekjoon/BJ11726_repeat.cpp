#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int solution(int n);

int main()
{
    int n;
    cin >> n;

    cout << solution(n) << endl;

    return 0;
}

int solution(int n) 
{
    const int MOD = 10007;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int index = 3; index <= n; index++) {
        dp[index] = (dp[index - 1] + dp[index - 2]) % MOD;
    }

    return dp[n];
}