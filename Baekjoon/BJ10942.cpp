#include <iostream>
#include <vector>
using namespace std;

int dp[2001][2001];

void solution(vector<int> numList);

int main()
{
    int n, q;
    vector<int> numList;
    
    cin >> n;
    numList.assign(n + 1, 0);

    for(int i=0; i<n; i++){
        cin >> numList[i + 1];
    }
    
    solution(numList);

    cin >> q;
    while(q--) {
        int start, end;
        cin >> start >> end;
        cout << dp[start][end] << endl;
    }

    return 0;
}

void solution(vector<int> numList) {
    int len = numList.size() - 1;

    // 1 자리
    for(int index = 1; index <= len; index++) {
        dp[index][index] = 1;
    }

    // 2 자리
    for(int index = 1; index < len; index++) {
        if(numList[index] == numList[index + 1]) {
            dp[index][index + 1] = 1;
        }
    }

    // 3 자리 이상
    for(int diff = 2; diff < len; diff++) {
        for(int start = 1; start <= len - diff; start++) {
            int end = start + diff;
            if(numList[start] == numList[end] && dp[start + 1][end - 1] == 1) {
                dp[start][end] = 1;
            }
        }
    }
}