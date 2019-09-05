#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int triangle[501][501];
int solution(int n);

int main()
{
    int n;

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> triangle[i][j];
        }
    }
    cout << solution(n) << endl;

    return 0;
}

int solution(int n)
{
    dp[1][1] = triangle[1][1];
    
    for (int floor = 2; floor <= n; floor++) {
        for (int index = 1; index <= floor; index++) {
            dp[floor][index] = max(dp[floor - 1][index - 1], dp[floor - 1][index]) + triangle[floor][index];
        }
    }

    int max = 0;
    for(int index = 1; index <= n; index++) {
        if (max < dp[n][index]) {
            max = dp[n][index];
        }
    }

    return max;
}