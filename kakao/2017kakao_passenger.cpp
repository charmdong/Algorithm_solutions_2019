#include <iostream>
#include <vector>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> map)
{
    vector<vector<int>> vertical(501, vector<int>(501, 0));
    vector<vector<int>> horizon(501, vector<int>(501, 0));

    vertical[1][1] = horizon[1][1] = 1;
    for (int row = 1; row <= m; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if(map[row-1][col-1] == 0) {
                vertical[row][col] += (vertical[row-1][col] + horizon[row][col-1]) % MOD;
                horizon[row][col] += (vertical[row-1][col] + horizon[row][col-1]) % MOD;
            }
            else if(map[row-1][col-1] == 2) {
                vertical[row][col] = vertical[row-1][col];
                horizon[row][col] = horizon[row][col-1];
            } else {
                vertical[row][col] = 0;
                horizon[row][col] = 0;
            }
        }
    }

    return vertical[m][n] % MOD;
}