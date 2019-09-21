/**
 * PG : 타일 장식물
 */ 
#include <iostream>
#include <vector>

using namespace std;

long long solution(int N) {
    vector<long long> dp(N + 1, 0);

    dp[1] = 4;
    dp[2] = 6;

    for(int i=3; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}