#include <iostream>
#include <vector>
#define DIV 1000000007
using namespace std;

vector<vector<int>> board;
vector<vector<int>> dp;
int solution(int, int, vector<vector<int>>);

int main()
{
    cout << solution(4, 3, {{2,2}}) << endl;
    return 0;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    board.assign(n + 1, vector<int>(m + 1, 1));
    dp.assign(n + 1, vector<int>(m + 1, 0));

    for(vector<int> puddle : puddles) {
        int x = puddle[0];
        int y = puddle[1];

        board[y][x] = 0;
    }

    dp[1][1] = 1;
    for(int row = 1; row <= n; row++) {
        for(int col = 1; col <= m; col++) {
            if(row == 1 && col == 1) {
                continue;
            }
            dp[row][col] = (board[row][col] == 0) ? 0 : (dp[row - 1][col] + dp[row][col - 1]) % DIV;
        }
    }

    return dp[n][m];
}