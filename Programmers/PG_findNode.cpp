/**
 * PG - 가장 먼 노드 갯수 구하기 Lv3
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> distList;
vector<bool> visited;
int solution(int, vector<vector<int>>);
void bfs(vector<vector<int>>);

int main()
{
    int n;
    cin >> n;
    cout << solution(n, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
    return 0;
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1, vector<int>());
    int row = edge.size();

    distList.assign(n + 1, 0);
    visited.assign(n + 1, false);
    for(int i=0; i<row; i++) {
        int src = edge[i][0];
        int des = edge[i][1];

        graph[src].push_back(des);
        graph[des].push_back(src);
    }

    bfs(graph);

    int maxVal = *max_element(distList.begin(), distList.end());
    return count(distList.begin(), distList.end(), maxVal);
}

void bfs(vector<vector<int>> graph) {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int index = 0; index < graph[now].size(); index++) {
            int next = graph[now][index];

            if(!visited[next]) {
                visited[next] = true;
                distList[next] = distList[now] + 1;
                q.push(next);
            }
        }
    }
}