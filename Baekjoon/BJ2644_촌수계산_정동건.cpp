/**
 * @author : donggun.chung
 * @date : 2020.02.12
 * @site : BOJ
 * @prob_Info : 2644 촌수 계산 
 * @time : 0ms
 * @memory : 1988KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, src, des, answer;
vector<vector<int>> graph;
vector<int> dist;
vector<bool> visited;

int solution();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cin >> src >> des;
    cin >> m;

    graph.assign(n + 1, vector<int>());
    dist.assign(n + 1, 0);
    visited.assign(n + 1, false);

    int child, parent;
    for(int index = 0; index < m; index++) {
        cin >> child >> parent;

        graph[child].push_back(parent);
        graph[parent].push_back(child);
    }

    answer = solution();

    if(answer == 0){
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}

int solution() {
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(now == des) {
            break;
        }

        for(int index = 0; index < graph[now].size(); index++) {
            int next = graph[now][index];

            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                dist[next] = dist[now] + 1;
            }
        }
    }

    return dist[des];
}