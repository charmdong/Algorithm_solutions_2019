#include <iostream>
#define DIV 10007
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

int solution(int n) {
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;

    for(int index = 4; index <= n; index++) {
        dp[index] = (2 * dp[index - 2] + dp[index - 1]) % DIV;
    }
    return dp[n];
}