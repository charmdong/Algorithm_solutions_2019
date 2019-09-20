#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int solution(vector<vector<int>> triangle);

int solution(vector<vector<int>> triangle) {
    int height = triangle.size();

    dp.assign(height, vector<int>(height, 0));
    dp[0][0] = triangle[0][0];

    for(int row = 1; row < height; row++) {
        for(int col = 0; col <= row; col++) {
            if(col == 0) {
                dp[row][col] = dp[row - 1][col];
            } else if(col == row) {
                dp[row][col] = dp[row - 1][col - 1];
            } else {
                dp[row][col] = max(dp[row - 1][col - 1], dp[row - 1][col]);
            }
            dp[row][col] += triangle[row][col];
        }
    }

    return *max_element(dp.back().begin(), dp.back().end());
}

int main()
{
    cout << solution({{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}}) << endl;
    return 0;
}