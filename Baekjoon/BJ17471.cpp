/**
 * @author : donggun.chung
 * @date : 2020.02.15
 * @site : BOJ
 * @prob_Info : 17471 게리맨더링 
 * @time : 0ms
 * @memory : 1992KB
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits.h>
using namespace std;

int answer = INT_MAX;
int N, total;
vector<vector<int>> graph;
vector<int> pCnt;
vector<bool> visited;

void solution();
void divideArea(int cnt, int current, int st);
bool isConnected(vector<int>& part);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int adjCnt, des;

    cin >> N;

    graph.assign(N + 1, vector<int>());
    pCnt.assign(N + 1, 0);

    for(int iter = 1; iter <= N; iter++) {
        cin >> pCnt[iter];
        total += pCnt[iter];
    }

    for(int index = 1; index <= N; index++) {
        cin >> adjCnt;

        for(int iter = 0; iter < adjCnt; iter++) {
            cin >> des;

            graph[index].push_back(des);
            graph[des].push_back(index);
        }
    }

    solution();
    cout << answer << endl;

    return 0;
}

void solution() {
    for(int mod = 1; mod <= N / 2; mod++) {
        visited.assign(N + 1, false);
        divideArea(0, 1, mod);
    }

    if(answer == INT_MAX) {
        answer = -1;
    }
}
// TODO: [1,2,3], [4,5,6] / [4,5,6,], [1,2,3] 과 같이 중복되는 경우 탐색 안 하도록 수정
void divideArea(int cnt, int current, int st) {
    if(cnt == st) {
        vector<int> first, second;

        for(int index = 1; index <= N; index++) {
            if(!visited[index]) {
                first.push_back(index);
            } else{
                second.push_back(index);
            }
        }

        if(isConnected(first) && isConnected(second)) {
            int sum = 0;

            for(int iter = 0; iter < first.size(); iter++) {
                sum += pCnt[first[iter]];
            }

            //cout << "SUM : " << sum << endl;

            int diff = abs(total - sum - sum);
            //cout << "DIFF : " << diff << endl;
            if(answer > diff) {
                answer = diff;
            }
        }
    }

    for(int index = current; index <= N; index++) {
        if(!visited[index]) {
            visited[index] = true;
            divideArea(cnt + 1, index + 1, st);
            visited[index] = false;
        }
    }
}

bool isConnected(vector<int>& part) {
    if(part.size() == 1) {
        return true;
    }

    vector<bool> visited(N + 1, true);

    for(int index = 0; index < part.size(); index++) {
        visited[part[index]] = false;
    }
    
    queue<int> q;
    
    q.push(part[0]);
    visited[part[0]] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int index = 0; index < graph[now].size(); index++) {
            int next = graph[now][index];

            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    for(int index = 1; index <= N; index++) {
        if(!visited[index]) {
            return false;
        }
    }

    return true;
}