#include <iostream>
#include <vector>

using namespace std;

int V, E, K;
vector<vector<pair<int, int>>> graph;

void solution();
void dfs(int& min, int src, int des, int total = 0);

// TODO: Dijkstra 사용
int main()
{
    int u, v, w;

    cin >> V >> E;
    graph.assign(V + 1, vector<pair<int, int>>());
    cin >> K;

    for(int cnt = 0; cnt < E; cnt++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    solution();

    return 0;
}

void solution() {
    vector<int> result(V + 1, 0);

    for(int index = 1; index <= V; index++) {
        if(index == K) {
            continue;
        }

        int min = 3000001;
        dfs(min, K, index);
        result[index] = min;
    }

    for(int index = 1; index <= V; index++) {
        if(result[index] == 3000001) {
            cout << "INF\n";
        } else {
            cout << result[index] << endl;
        }
    }
}

void dfs(int& min, int src, int des, int total) {
    if(src == des) {
        if(total < min) {
            min = total;
        }
        return;
    }

    for(int next = 0; next < graph[src].size(); next++) {
        dfs(min, graph[src][next].first, des, total + graph[src][next].second);
    }
}