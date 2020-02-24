/**
 * @author : donggun.chung
 * @date : 2020.02.15
 * @site : BOJ
 * @prob_Info : 5567 결혼식
 * @time : 0ms
 * @memory : 2252KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;

int bfs(int start = 1);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    graph.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);

    int src, des;
    for(int index = 0; index < M; index++) {
        cin >> src >> des;

        graph[src].push_back(des);
        graph[des].push_back(src);
    }

    cout << bfs() << endl;

    return 0;
}

int bfs(int start) {
    int answer = -1;
    queue<pair<int, int>> q;

    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        if(now.second >= 3) {
            break;
        }
        answer++;

        for(int index = 0; index < graph[now.first].size(); index++) {
            int next = graph[now.first][index];

            if(!visited[next]) {
                visited[next] = true;
                q.push({next, now.second + 1});
            }
        }
    }

    return answer;
}