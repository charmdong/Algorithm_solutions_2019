#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int dp[10001];
int solution(int n);

int main()
{
    int n;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> wine[i + 1];
    }
    cout << solution(n) << endl;

    return 0;
}

int solution(int n)
{
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for(int index = 3; index <= n; index++) {
        dp[index] = max(dp[index - 2], dp[index - 3] + wine[index - 1]) + wine[index];
        dp[index] = max(dp[index - 1], dp[index]);
    }

    return dp[n];
}