/**
 * @author : donggun.chung
 * @date : 2020.02.15
 * @site : BOJ
 * @prob_Info : 11558 The Game of Death
 * @time : 4ms
 * @memory : 2116KB
 */

#include <iostream>
#include <vector>
using namespace std;

int T, N, answer;
vector<int> player;
vector<bool> visited;

void solution(int cur = 1, int cnt = 0);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for(int test = 1; test <= T; test++) {
        cin >> N;

        player.assign(N + 1, 0);
        visited.assign(N + 1, false);

        for(int index = 1; index <= N; index++) {
            cin >> player[index];
        }

        solution();
        cout << answer << endl;
        answer = 0;
    }

    return 0;
}

void solution(int cur, int cnt) {
    if(cur == N) {
        answer = cnt;
        return;
    }

    visited[cur] = true;

    int next = player[cur];

    if(!visited[next]) {
        solution(next, cnt + 1);       
    } 
}