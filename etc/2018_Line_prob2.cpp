/**
 * 시간복잡도 : O(n^2)
 * 공간복잡도 : O(n^2)
 */

#include <iostream>
#include <vector>
#define DIV 1003001
using namespace std;

int solution(vector<vector<int>>, int, int, int);

int main()
{
    int testCase;
    cin >> testCase;
    for(int test = 0; test < testCase; test++) {
        int n, k, m;
        vector<vector<int>> dp;
        cin >> n >> k >> m;
        dp.assign(n+1, vector<int>());
        cout << solution(dp, n, k, m) << endl;
    }
    return 0;
}

int solution(vector<vector<int>> dp, int n, int k, int m) {
    // k : 구매 가능한 개수, m : 구매할 스티커 개수, k - m : 구매할 테마 개수
    dp[0].assign(1, 0);
    dp[1].assign(2, 0);
    dp[0][0] = dp[1][0] = dp[1][1] = 1;

    for(int row = 2; row <= n; row++) {
        dp[row].assign(row + 1, 0);
        for(int col = 0; col <= row; col++) {
            if(col == 0 || col == row) {
                dp[row][col] = 1;
                continue;
            }

            dp[row][col] = (dp[row-1][col-1] + dp[row-1][col]) % DIV;
        }
    } 

    return (dp[n][m] * dp[n][k-m]) % DIV;
}