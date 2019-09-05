#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[301];
int solution(int n, vector<int> stairs);

int main()
{
    int n;
    vector<int> stairs;

    cin >> n;
    stairs.assign(n + 1, 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> stairs[i + 1];
    }
    
    cout << solution(n, stairs) << endl;

    return 0;
}

int solution(int n, vector<int> stairs)
{
    dp[0] = stairs[0];
    dp[1] = max(stairs[0] + stairs[1], stairs[1]);
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (size_t i = 3; i <= n; i++)
    {
        dp[i] = stairs[i] + max(dp[i - 2], stairs[i - 1] + dp[i - 3]);
    }
    
    return dp[n];
}