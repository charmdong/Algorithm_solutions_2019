/**
 * @author : donggun.chung
 * @date : 2020.02.12
 * @site : BOJ
 * @prob_Info : 2961 도영이가 만든 맛있는 음식
 * @time : 0ms
 * @memory : 1984KB
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

int N;
int answer = INT_MAX;
vector<pair<int, int>> taste, res;

void solution(int cnt = 0);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    taste.assign(N, {0, 0});

    for(int index = 0; index < N; index++) {
        cin >> taste[index].first >> taste[index].second; 
    }

    solution();

    cout << answer << endl;

    return 0;
}

void solution(int cnt) {
    if(cnt > 0) {
        int sTotal = 1;
        int bTotal = 0;

        for(auto p : res) {
            sTotal *= p.first;
            bTotal += p.second;
        }

        if(answer > abs(sTotal - bTotal)) {
            answer = abs(sTotal - bTotal);
        }
    }

    for(int index = cnt; index < N; index++) {
        res.push_back(taste[index]);
        solution(index + 1);
        res.pop_back();
    }
}