#include <iostream>
#include <vector>
#define MAX_LEN 1000
using namespace std;

vector<int> dp;
int solution(vector<int> numList);

int main()
{
    int testCase, n;

    cin >> testCase;

    for(int test = 1; test <= testCase; test++) {
        vector<int> numList;
        int num;
        dp.assign(MAX_LEN, 0);

        cin >> n;
        for (int index = 0; index < n; index++) {
            cin >> num;
            numList.push_back(num);
        }

        cout << "#" << test << " " << solution(numList) << endl;
    }

    return 0;
}

int solution(vector<int> numList) {
    int answer = 0;

    dp[0] = 1;

    for(int cur = 1; cur < numList.size(); cur++) {
        dp[cur] = 1;

        for(int prev = 0; prev < cur; prev++) {
            if(numList[cur] > numList[prev] && dp[cur] <= dp[prev]) {
                dp[cur] = dp[prev] + 1;
            } else if(numList[cur] == numList[prev]) {
                dp[cur] = dp[prev];
            }
        }
    }

    for(int index = 0; index < numList.size(); index++) {
        answer = (answer < dp[index]) ? dp[index] : answer;
    }
    
    return answer;
}