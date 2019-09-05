#include <iostream>
#include <algorithm>
#define RED 0
#define GREEN 1
#define BLUE 2
using namespace std;

int rgb[1001][3];
int dp[1001][3];

int solution(int n);

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            cin >> rgb[i][j];
        }
    }

    cout << solution(n) << endl;

    return 0;
}

int solution(int n)
{
    for(int index = 1; index <= n; index++) {
        // Get all results of cases (Red, Green, Blue)
        dp[index][RED] = min(dp[index - 1][GREEN], dp[index - 1][BLUE]) + rgb[index][RED];
        dp[index][GREEN] = min(dp[index - 1][RED], dp[index - 1][BLUE]) + rgb[index][GREEN];
        dp[index][BLUE] = min(dp[index - 1][RED], dp[index - 1][GREEN]) + rgb[index][BLUE];
    }

    return min(min(dp[n][RED], dp[n][GREEN]), dp[n][BLUE]);
}