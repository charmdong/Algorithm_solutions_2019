/**
 * @author : donggun.chung
 * @date : 2020.02.05
 * @site : BOJ
 * @prob_Info : 13023 ABCDE 
 * @time : 
 * @memory : 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, answer;
vector<vector<int>> graph;
vector<bool> visited;

int bfs(int start);
void dfs(int current, int cnt = 1);

int main()
{
    int src, des;
    cin >> n >> m;

    graph.assign(n, vector<int>());

    for(int index = 0; index < m; index++) {
        cin >> src >> des;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }    

    for(int index = 0; index < n; index++) {
        visited.assign(n, false);
        dfs(index);
        if(answer) {
            break;
        }
    }
    
    cout << answer << endl;

    return 0;
}

void dfs(int current, int cnt) {
    if(answer == 1) {
        return;
    }
    
    visited[current] = true;

    if(cnt == n) {
        answer = 1;
        return;
    }

    for(int index = 0; index < graph[current].size(); index++) {
        int next = graph[current][index];

        if(!visited[next]) {
            dfs(next, cnt + 1);
            visited[next] = false;
        }
    }
}