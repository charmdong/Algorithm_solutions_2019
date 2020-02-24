/**
 * @author : donggun.chung
 * @date : 2020.02.09
 * @site : BOJ
 * @prob_Info : 2225 합분해 
 * @time : 0ms
 * @memory : 2608KB
 */

#include <iostream>
#define MAX 200
#define MOD 1000000000

using namespace std;

int N, K;
int combination[2 * MAX][2 * MAX];

void initCombination();

int main()
{
    cin >> N >> K;

    initCombination();

    cout << combination[N + K - 1][N] % MOD << endl;

    return 0;
}

void initCombination() {
    for(int n = 0; n < 2 * MAX; n++) {
        combination[n][0] = combination[n][n] = 1;
    }

    for(int n = 2; n < 2 * MAX; n++) {
        for(int r = 1; r < n; r++) {
            combination[n][r] = (combination[n - 1][r] + combination[n - 1][r - 1]) % MOD;
        }
    }
}